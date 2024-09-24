//
//  ViewController.m
//  example
//
//  Created by ShiChangShun on 2021/12/21.
//

#import "ViewController.h"
#import <TZImagePickerController/TZImagePickerController.h>
#import <SWJianbeiSDK/SWJianbeiSDK.h>
#import "EditViewController.h"

@interface ViewController ()<TZImagePickerControllerDelegate>

@property (nonatomic ,strong) BPDownloader *downloader;

@property (nonatomic, strong) UILabel *label;

@end

@implementation ViewController

//选择本地相册资源 转换成mixwindow 对象
- (void)selectLocalAsset:(id)sender {
    
    TZImagePickerController *imagePickerVc = [[TZImagePickerController alloc]initWithMaxImagesCount:20 * 60 delegate:self];
    imagePickerVc.allowPickingGif = NO; // 暂不支持 gif
    imagePickerVc.allowTakeVideo = NO;  // 不能拍摄
    imagePickerVc.allowTakePicture = NO;    //不能拍摄照片
    imagePickerVc.allowPickingMultipleVideo = YES;  // 支持 video 多选
    imagePickerVc.showSelectedIndex = YES;  // 显示选中的图片的序号
    imagePickerVc.isSelectOriginalPhoto = YES;  // 默认使用原图
    imagePickerVc.naviBgColor = [UIColor blackColor];
    imagePickerVc.modalPresentationStyle = UIModalPresentationFullScreen;
    
    [imagePickerVc setDidFinishPickingPhotosHandle:^(NSArray<UIImage *> *photos, NSArray *assets, BOOL isSelectOriginalPhoto) {
        
        BPVideoMaskType maskType = BPVideoMaskType3x4;  // 默认比例
        
        //**********将phasset对象 转换成 BPMixMedia对象，再加入BPMixWindow 中******
        
        [BPMixModelTool bp_onPhotoPickerCallback:photos assetx:assets needZoomEffect:YES mask: maskType  complete:^(NSMutableArray<BPMixMediaView *> * mixArray) {
            BPMixWindow *mixWindowModel = [[BPMixWindow alloc] initWithVidoes:mixArray videoMaskType: BPVideoMaskType3x4];
            
            EditViewController* editVC = [[EditViewController alloc]init];
            editVC.windowModel = mixWindowModel;
            
            [self.navigationController pushViewController:editVC animated:YES];
        }];

    }];
    
    [[UIApplication sharedApplication].keyWindow.rootViewController presentViewController:imagePickerVc animated:YES completion:nil];
}
//选择云端资源
- (void)cloudAsset:(id)sender {
    
    //需要先下载资源到本地，然后转换成 BPMixWindow 对象
    
    //测试视频地址 不一定好用
    NSString *videoUrl = @"https://media.w3.org/2010/05/sintel/trailer.mp4";
    
    self.downloader = [[BPDownloader alloc] initWithUrl: videoUrl localPath:nil];
   
    [self.downloader startSessionWithProgressBlock:^(double progress) {
        NSLog(@"download progress = %f", progress);
        dispatch_async(dispatch_get_main_queue(), ^{
            self.label.text = [NSString stringWithFormat:@"进度：%% %.0f", progress];
        });
        
    } complete:^(NSString * _Nonnull filePath, NSError * _Nullable error) {
        if (!error) {
           
            NSLog(@"download success = %@", filePath);
            
            NSString *localPath = filePath;
            
            AVURLAsset * asset = [AVURLAsset assetWithURL:[NSURL fileURLWithPath:filePath]];
            CMTime   time = [asset duration];
            int duration = ceil(time.value * 1000/time.timescale);
            
            NSString *relativePath = [BPDownloader getRelativePathWithLocalPath:filePath];
            
            NSMutableArray *array = [NSMutableArray arrayWithCapacity:10];
            
            BPMixMediaSource *source = [[BPMixMediaSource alloc] initWithSandboxPath: relativePath];
            BPMixVideoView *video = [[BPMixVideoView alloc] initWithSource:source];
            video.mediaDuration = duration;  //视频的时长 ms
            CGSize size = [BPCommonMethod getVideoResulosionWithFFmpeg: localPath];
            BPMixCrop *crop = [[BPMixCrop alloc] initWithVideoOriginSize:size cropRatio:BPVideoMaskType3x4];
            video.crop = crop;
            
            [array addObject:video];
            
            BPMixWindow * mixWindowModel = [[BPMixWindow alloc] initWithVidoes:array];
            
            EditViewController* editVC = [[EditViewController alloc]init];
            editVC.windowModel = mixWindowModel;
            
            [self.navigationController pushViewController:editVC animated:YES];
            
        }else {
            NSLog(@"download failed");
        }
    }];
}


- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    
    UIButton *button1 = [UIButton buttonWithType:UIButtonTypeSystem];
    button1.frame = CGRectMake(30, 100, 120, 44);
    [button1 setTitle:@"选择本地素材" forState:UIControlStateNormal];
    button1.titleLabel.font = [UIFont systemFontOfSize:18];
    [button1 addTarget:self action:@selector(selectLocalAsset:) forControlEvents:UIControlEventTouchUpInside];
    
    [self.view addSubview:button1];
    
    
    UIButton *button2 = [UIButton buttonWithType:UIButtonTypeSystem];
    button2.frame = CGRectMake(30, 180, 120, 44);
    [button2 setTitle:@"选择云端素材" forState:UIControlStateNormal];
    button2.titleLabel.font = [UIFont systemFontOfSize:18];
    [button2 addTarget:self action:@selector(cloudAsset:) forControlEvents:UIControlEventTouchUpInside];
    
    [self.view addSubview:button2];
    
    self.label = [UILabel new];
    self.label.frame = CGRectMake(30, 250, 120, 44);
    
    self.label.text = @"进度：% 0";
    
    [self.view addSubview:self.label];
    
    
}

/*  添加素材
 
 ---------  本地素材 --------------
 
 1、去相册拿到phAsset 对象
 2、将PHAsset转换成 BPMixMediaView  使用当前播放器的比例 mastType
 [BPMixModelTool bp_onPhotoPickerCallback:photos assetx:assets needZoomEffect:YES mask: maskType  complete:^(NSMutableArray<BPMixMediaView *> * mixArray) {
 
 }];
 3、将mixArray 插入到 mixWindow 中（index 为 想要插入的位置）

 for (BPMixView* view in mixArray) {
     [self.windowModel.video insertVidoe:view atIndex:index];
 }
 
 ----------- 云端素材 需先下载到沙盒 ----------------
 
 1、用文件路径创建BPMixVideoView 对象（ relativePath 去掉 NSHomeDirectory() 后的绝对路径，fullPath 包含根路径）
   BPMixMediaSource* source = [[BPMixMediaSource alloc] initWithSandboxPath:relativePath];
   BPMixVideoView* videoView = [[BPMixVideoView alloc] initWithSource:source];
   videoView.mediaDuration = xxxx    // 视频时长

   CGSize size = [BPCommonMethod getVideoResulosionWithFFmpeg:fullPath];
 
   CGSize remakeSize;
   if ((asset.pixelWidth < asset.pixelHeight) && (size.width > size.height)) {
       remakeSize = CGSizeMake(size.height, size.width);
   }else {
       remakeSize = CGSizeMake(size.width, size.height);
   }
   videoView.crop = [[BPMixCrop alloc] initWithVideoOriginSize:remakeSize cropRatio:type];
 
 2、插入到windowModel中
   [self.windowModel.video insertVidoe:view atIndex:index];
 
 **/


@end
