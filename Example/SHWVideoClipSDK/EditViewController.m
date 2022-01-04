//
//  EditViewController.m
//  example
//
//  Created by ShiChangShun on 2021/12/23.
//

#import "EditViewController.h"
#import "EditCollectionViewCell.h"

#import <SWJianbeiSDK/SWJianbeiSDK.h>
#import <SWMixLibsSDK/SWMixLibsSDK.h>

#define BPMediaDirectory @"/Documents/bp_media/" //资源文件夹 固定不可修改，否则不起作用

@interface EditViewController ()<UICollectionViewDelegate,UICollectionViewDataSource>

@property (weak, nonatomic) IBOutlet UIView *videoView;
@property (weak, nonatomic) IBOutlet UICollectionView *collectionView;

/// 播放器的 view 需要根据 画幅 切换 size
@property (nonatomic, strong) BPVideoPlayer *videoPlayer;
@property (nonatomic, assign) BPPlayerSate playerState;

@property (nonatomic,strong) BPMixWindow *model;

@end

@implementation EditViewController

- (BPPlayerSate)playerState {
    return self.videoPlayer.state;
}
//初始化videoPlayer
- (BPVideoPlayer *)videoPlayer {
    if (!_videoPlayer) {
        CGSize size = CGSizeMake([UIScreen mainScreen].bounds.size.width, 300);
        // 视频比例
        BPVideoMaskType aspect = self.model.videoMaskType;
        CGRect rect = [BPEditorVCUtil playerFrameWithContenViewSize:size aspect:aspect];
        // 初始化播放器 ，默认播放全部视频
        BPMixWindow *window = self.model;//修改copy后的对象，不影响原对象
        window.startIndex = 0; //开始
        window.endIndex = -1; //播放全部 默认
        _videoPlayer = [[BPVideoPlayer alloc] initWithFrame:rect playData:window];
    }
    return _videoPlayer;
}

- (void)viewDidLayoutSubviews {
    [super viewDidLayoutSubviews];
}

- (void)viewDidLoad {
    [super viewDidLoad];
    
    self.model = [self.windowModel copy];
    //将sdk 的playerView添加到 videoView上
    [self.videoView addSubview:self.videoPlayer.playerView];
    [self.videoPlayer play:YES];
    
    [self.collectionView registerNib:[UINib nibWithNibName:@"EditCollectionViewCell" bundle:nil] forCellWithReuseIdentifier:@"EditCollectionViewCell"];
}

- (void)viewWillDisappear:(BOOL)animated {
    [super viewWillAppear:animated];
//    [self.videoPlayer pause];
}

#pragma mark ---- UserAction

//播放  暂停
- (IBAction)play:(id)sender {
    
    if (self.videoPlayer.state == BPPlayerSate_Pause) {
        [self.videoPlayer play:YES];
    }else if (self.videoPlayer.state == BPPlayerSate_Play) {
        [self.videoPlayer pause];
    }
}

//生成视频   合成
- (IBAction)generate:(id)sender {
    //暂停播放
    [self.videoPlayer pause];
    
    //合成输出路径
    NSString *documentPath = [NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES) firstObject];
    NSString *outPath = [documentPath stringByAppendingFormat:@"/result.mp4"];
    
    //合成工具BPCombineProvider 合成
    BPCombineProvider *combineProvider = [[BPCombineProvider alloc]initWithMixWindow:self.model outputPath:outPath];
    
    [combineProvider asyncCompositeWithResult:^(BOOL success, float duration) {
        if (success) {
            UISaveVideoAtPathToSavedPhotosAlbum(outPath, self, @selector(video:didFinishSavingWithError:contextInfo:), nil);
        }else {
            NSLog(@"合成失败");
        }
    }];
    
}

// 切换画幅比例
- (IBAction)changeVideoViewSize:(id)sender {
    CGSize size = [self.model.config getSize]; //获取当前video 的size.
    
/*  BPVideoMaskType_Origin     = 0, /// 使用视频原始尺寸
    BPVideoMaskType3x4         = 1, /// 3:4
    BPVideoMaskType1x1         = 2, /// 1:1
    BPVideoMaskType16x9        = 3, /// 16:9
*/
    NSInteger aspect = arc4random() % 4;
    CGRect newReact = [BPEditorVCUtil playerFrameWithContenViewSize:self.videoView.frame.size aspect: aspect];
    //更新比例
    [self.videoPlayer updatePlayerFrame:newReact videoSize:size];
    
    [self play];
}

- (void)play {
    [self.videoPlayer play:YES];
}

#pragma mark ---- 单个素材参数调整 -------------------

//倍速
- (IBAction)speed:(id)sender {
    
    // 播放的片段存放在BPMixWindow对象的.video.views的数组中，需要遍历，倍速参数可自由修改。
    // 0.5 1 2 3 4
    for (int i = 0; i < self.model.video.views.count; i++ ) {
        BPMixVideoView *video = self.model.video.views[i];
        if (![video isKindOfClass:[BPMixVideoView class]]) {
            NSLog(@"-- 图片素材不支持倍速");
            continue;
        }
//        if (i == 0) {//第一个片段
            video.speed = arc4random() % 4 + 1; //x倍播放
//        }else {//其他片段
//            video.speed = 0.5;//慢放
//        }
    }
    [self.videoPlayer updatePlayerData: self.model];
    [self.videoPlayer play:YES];
}


#pragma mark --- UICollectionViewDelegate ---


- (NSInteger)numberOfSectionsInCollectionView:(UICollectionView *)collectionView {
    return 1;
}
-(NSInteger)collectionView:(UICollectionView *)collectionView numberOfItemsInSection:(NSInteger)section {
    return 14;
}
- (__kindof UICollectionViewCell *)collectionView:(UICollectionView *)collectionView cellForItemAtIndexPath:(NSIndexPath *)indexPath {
    EditCollectionViewCell *cell = [collectionView dequeueReusableCellWithReuseIdentifier:@"EditCollectionViewCell" forIndexPath:indexPath];
    cell.titleLabel.textColor = [UIColor systemBlueColor];
    switch (indexPath.row) {
        case 0:
        {
            cell.titleLabel.text = @"静音";
        }
            break;
        case 1:
        {
            cell.titleLabel.text = @"截取2000-3000ms";
        }
            break;
        case 2:
        {
            cell.titleLabel.text = @"分割视频";
        }
            break;
        case 3:
        {
            cell.titleLabel.text = @"美颜";
        }
            break;
        case 4:
        {
            cell.titleLabel.text = @"裁剪";
        }
            break;
        case 5:
        {
            cell.titleLabel.text = @"音量";
        }
            break;
        case 6:
        {
            cell.titleLabel.text = @"变焦";
        }
            break;
        case 7:
        {
            cell.titleLabel.text = @"滤镜";
        }
            break;
        case 8:
        {
            cell.titleLabel.text = @"转场";
        }
            break;
        case 9:
        {
            cell.titleLabel.text = @"添加字幕";
        }
            break;
        case 10:
        {
            cell.titleLabel.text = @"添加音频";
        }
            break;
        case 11:
        {
            cell.titleLabel.text = @"贴图（图片）";
        }
            break;
        case 12:
        {
            cell.titleLabel.text = @"贴图（视频）";
        }
            break;
        case 13:
        {
            cell.titleLabel.text = @"清空所有特效";
        }
            break;
            
        default:
            break;
    }
    
    return cell;
}

- (void)collectionView:(UICollectionView *)collectionView didSelectItemAtIndexPath:(NSIndexPath *)indexPath {
    
    BPMixWindow *newModel = self.model;
    
    //默认处理第一个视频片段
    BPMixVideoView *video = [newModel.video.views firstObject];
    
    switch (indexPath.row) {
        case 0: //静音
        {
            if (![video isKindOfClass:[BPMixVideoView class]]) {
                NSLog(@"-- 图片素材不支持");
                return;
            }
            //静音
            video.rmSound = !video.rmSound;
        }
            break;
        case 1:
        {//截取
            
            video.cutStartTs = 2000;//截取开始时间
            video.cutEndTs = 3000; //截取结束时间
            
            // 截取后，需要做数据订正：移除或截取 超出主轴时长的副轴字幕、音乐
            [newModel bp_adjustAttachTime];
            
        }
            break;
        case 2:
        {
            //分割视频 --- 支持一个视频分割成多段
            if (!newModel.video.views.count) {
                return;
            }
            if (![video isKindOfClass:[BPMixVideoView class]]) {
                NSLog(@"-- 图片素材不支持分割");
                return;
            }
            
            NSMutableArray<BPMixVideoView *> *videoArray = [NSMutableArray array];
            // 按时间将一个视频分割成x段
            NSArray *array = @[@(2000),@(3000),@(5000),@(8000)];
            
            for (int i = 0; i < array.count + 1; i++) {
                //新建一个model
                BPMixVideoView* newVideo = [video copy];
                if (i == 0) {   // 第一个的 start 不变
                    
                } else {
                    //第二段的开始时间是上一段的结束时间
                    BPMixVideoView*lastVideo = videoArray[(i - 1)];
                    newVideo.cutStartTs = lastVideo.cutEndTs;
                }
                
                if (i == array.count) { // 最后一个的 cutEndTs 不变
                    
                } else {
                    newVideo.cutEndTs = [array[i] floatValue] * newVideo.speed;
                    
                    if (newVideo.cutEndTs >= newVideo.mediaDuration) {//截取超出范围
                        newVideo.cutEndTs = -1; //分割到结尾
                    }
                }
                
                [videoArray addObject:newVideo];
                
                if (newVideo.cutEndTs == -1) {
                    break;
                }
            }
            //获取视频的 index
            NSInteger index = [newModel.video.views indexOfObject:video];
            
            for (int i = 0; i < videoArray.count; i ++) {
                [newModel.video.views insertObject:videoArray[i] atIndex: index + i];
            }
            //移除被分割的整段视频
            [newModel.video.views removeObject:video];
            //播放分割后的最后一段视频
//            int startIndex = [@(newModel.video.views.count) intValue] - 1;
//            newModel.startIndex = startIndex;
//            newModel.endIndex = startIndex;
            
        }
            break;
        case 3:
        {//美颜
            
            if (![video isKindOfClass:[BPMixMediaView class]]) {
                NSLog(@"-- 美颜类型有误");
                return;
            }
            
            if ([video hadBeautifyFaceFilter]) {
                [video removeBeautifyFaceFilter];
            } else {
                [video addBeautifyFaceFilter];
            }
            
        }
            break;
        case 4:
        {//裁剪
            CGFloat videoHeight = video.crop.videoHeight;
//            CGFloat videoWidth = video.crop.videoWidth;
            video.rotation = 0;//默认 0°
            [video.crop updateCropRatioWithCropArea:CGRectMake(50, 100, 300, videoHeight-100)];
            
        }
            break;
        case 5:
        {//音量 0 ~ 1
            video.volume = 0.5;
            
        }
            break;
        case 6:
        {//变焦
            BPMixImageView* imageView = (BPMixImageView *)video;
            [imageView bp_addOrUpdateZoomFilterWithType:BPZoomType_ZoomOut];
        }
            break;
        case 7:
        {//滤镜
            if (![video isKindOfClass:[BPMixMediaView class]]) {
                NSLog(@"-- 滤镜类型有误");
                return;
            }
            NSArray *arr = @[@"冰淇淋", @"城市", @"初恋", @"纯净", @"粉嫩", @"古老", @"光华", @"海滩", @"假日", @"桔梗", @"洛丽塔", @"马卡龙", @"美味", @"慕斯", @"亲亲", @"青草", @"清新", @"日落", @"珊瑚", @"生动", @"甜美", @"小森林", @"小甜甜", @"新鲜", @"洋气", @"元气", @"原片", @"自然", @"crisp"];
            //移除
            if ([video hadStyleFilter]) {
                [video removeStyleFilter];
            }
            //添加风格滤镜
            NSString *newFilter = [NSString stringWithFormat:@"%@.png", [self transChineseStringToPingyin:arr[4]]];
            [video addStyleFilterWithName:newFilter];
            
        }
            break;
        case 8:
        {//转场  **********注： 片头片尾不能添加转场********
            if (newModel.video.views.count < 2) {
                return;
            }
            //获取片段尾部index
            NSInteger index = [newModel.video.views indexOfObject:video]+1;
            
            if (index < newModel.video.views.count) {
                if ([newModel.video.views[index] isKindOfClass:[BPMixTransitionView class]]) {
                    //已经添加了转场 移除当前转场
                    [newModel.video.views removeObjectAtIndex:index];
                }
            }
            BPMixTransitionView *transitionVideo = [[BPMixTransitionView alloc] init];
            //转场枚举 18种任选
            BPTransitionType type = arc4random()%18;
            transitionVideo.name = [BPTransitionTypeConvert nameWithType:type];
            //  在 window.views 插入转场
            [newModel.video insertVidoe:transitionVideo atIndex:index];
        }
            break;
        case 9:
        {//添加字幕
            //新建字幕对象
            BPMixSubtitleView *editModel = [[BPMixSubtitleView alloc]init];
            editModel.attachTime = 0;//开始
            editModel.detachTime = 12000;//结束
            
            //获取默认支持字体数组
            NSArray *fontArray = [BPCustomFontModel new].fonts;
            BPCustomFontModel *fontModel = fontArray[arc4random()%6];
            
            //创建字体对象
            BPMixFont *titleFont = [[BPMixFont alloc]init];
            titleFont.text = @"这是添加的字幕";
            titleFont.fontSize = 42;
            titleFont.font = fontModel.path;
            titleFont.fontColor = @"#FFABF87B";
            titleFont.strokeWidth = 1;
            titleFont.strokeAlpha = 0.3;
            
            editModel.titleFont = titleFont;
            editModel.shadow = YES; //是否存在阴影
            editModel.bgColor = @"#00000000"; //文字区域背景颜色
            editModel.topPadding = 24; //上边距
            editModel.leftPadding = 24;//左边距
            editModel.linePadding = 0; //行间距
            editModel.shadowPaddingX = 8; //阴影X轴偏移量
            editModel.shadowPaddingY = -8; //阴影外轴偏移量
           
            editModel.titleFont = titleFont;
            
            editModel.subtitleType = BPEditSubtitleType_BackShaw;
            
            
            BPMixLayout *layout = [[BPMixLayout alloc]init];

            UIFont *font = [UIFont fontWithName:fontModel.name size:editModel.titleFont.fontSize];
           
            //获取视频宽高
            CGSize size = CGSizeMake(newModel.config.width, newModel.config.height);
            
            //获取文字宽高
            CGSize titleSize = [BPCommonMethod getWidthFromText:editModel.titleFont.text WithSize:font AboutWidth:size.width AndHeight:size.height];
            
            CGFloat fontWidth = 0.0;
            CGFloat fontHeight = 0.0;
            
            fontWidth = titleSize.width+editModel.leftPadding*2;
            fontHeight = titleSize.height+editModel.topPadding*2;
//            CGFloat rx = (size.width-fontWidth)/2; //视频宽度 - 字体宽度
            CGFloat ry = (size.height-fontHeight); //视频真实高度-字体高度
            //字幕添加的位置
            layout.rx = arc4random()%llroundf(size.width-fontWidth); //随机 0 ~ 最右
            layout.ry = arc4random()%llroundf(ry); //随机 0 ~ 最底部
            layout.width = fontWidth;
            layout.height = fontHeight;
            
            editModel.layout = layout;
            
            [newModel.attaches.views addObject:editModel];
            
        }
            break;
        case 10:
        {//添加音频
            
            if (newModel.audios.count > 0) {//移除音频
                [newModel.audios removeObjectAtIndex:0];
            }else {
                
                //1、将云端资源下载到沙盒或bundle中的音频资源 copy 到沙盒路径（NSHomeDirectory()/Documents/bp_media/xxx.mp3）中
                NSString *fileName = @"test1.mp3";
                NSString *path = [[NSBundle mainBundle] pathForResource:@"test1" ofType:@"mp3"];
                
                NSString *mediaURL = [BPMediaDirectory stringByAppendingPathComponent:fileName];
                NSString* fullPath = [NSString stringWithFormat:@"%@%@", NSHomeDirectory(), mediaURL];
                
                if (![[NSFileManager defaultManager] fileExistsAtPath:fullPath]) {
                    BOOL isSuccess = [[NSFileManager defaultManager] copyItemAtPath:path toPath:fullPath error:nil];
                    if (!isSuccess) {
                        NSLog(@"");
                        return;
                    }
                }
                //2、创建音频对象
                BPMixAudio *audioModel = [[BPMixAudio alloc]init];
                audioModel.attachTime = 0;//音频从开始切入
                audioModel.fileName = fileName;
                audioModel.type = BPAudioType_BGM;//音乐
                audioModel.cutStartTs = 0.0; //音频开始
                audioModel.cutEndTs = 3000; //音频结束 3s
                audioModel.detachTime = audioModel.cutEndTs+audioModel.attachTime;
                audioModel.volumeFadeInDuration = 1000.0; //淡入
                audioModel.volumeFadeOutDuration = 0.0; //淡出
                audioModel.repeat = false;
                //3、插入MixWindModel 中
                [newModel.audios addObject:audioModel];
                
                NSString *fileName1 = @"test.mp3";
                NSString *path1 = [[NSBundle mainBundle] pathForResource:@"test" ofType:@"mp3"];
                
                NSString *mediaURL1 = [BPMediaDirectory stringByAppendingPathComponent:fileName1];
                NSString* fullPath1 = [NSString stringWithFormat:@"%@%@", NSHomeDirectory(), mediaURL1];
                
                if (![[NSFileManager defaultManager] fileExistsAtPath:fullPath1]) {
                    BOOL isSuccess1 = [[NSFileManager defaultManager] copyItemAtPath:path1 toPath:fullPath1 error:nil];
                    if (!isSuccess1) {
                        NSLog(@"");
                        return;
                    }
                }
                BPMixAudio *audioModel1 = [[BPMixAudio alloc]init];
                audioModel1.attachTime = 3001;//从3s开始切入
                audioModel1.fileName = @"test.mp3";
                audioModel1.type = BPAudioType_BGM;//音乐
                audioModel1.cutStartTs = 3000; //音频开始
                audioModel1.cutEndTs = 7000; //截取4s的音频
                audioModel1.detachTime = video.mediaDuration;
                audioModel1.volumeFadeInDuration = 0; //淡入
                audioModel1.volumeFadeOutDuration = 0; //淡出
                audioModel1.repeat = YES;
                
                [newModel.audios addObject:audioModel1];
            }
            
        }
            break;
        case 11:
        {//添加贴图（图片）
            //移除已添加的特效
            if (newModel.attaches.views.count) {
                [newModel.attaches.views enumerateObjectsUsingBlock:^(__kindof BPMixView * _Nonnull obj, NSUInteger idx, BOOL * _Nonnull stop) {
                    if ([obj isKindOfClass:[BPMixImageView class]]) {
                        [newModel.attaches.views removeObject:obj];
                    }
                }];
  
            }
            NSString *fileName = @"icon_hzw.jpg";
            NSString *path = [[NSBundle mainBundle] pathForResource:fileName ofType:nil];
            
            NSString *newFileName = [NSString stringWithFormat:@"%@.png",[NSUUID UUID].UUIDString];
            NSString *relativePath = [NSString stringWithFormat:@"%@%@", BPMediaDirectory, newFileName];
            
            NSString* fullPath = [NSString stringWithFormat:@"%@%@",NSHomeDirectory(), relativePath];
            
            if (![[NSFileManager defaultManager] fileExistsAtPath:fullPath]) {
                BOOL isSuccess = [[NSFileManager defaultManager] copyItemAtPath:path toPath:fullPath error:nil];
                if (!isSuccess) {
                    NSLog(@"");
                    return;
                }
            }
            BPMixMediaSource* source = [[BPMixMediaSource alloc] initWithSandboxPath:relativePath];
            BPMixImageView *stickerView  = [[BPMixImageView alloc]initWithSource:source];
            stickerView.mType = Mix_Picture;
            stickerView.attachTime = 0;
//            stickerView.mediaDuration = -1; //一直显示
            stickerView.mediaDuration = 2000; //2s
            
            BPMixLayout *layout = [[BPMixLayout alloc]init];
            layout.rx = 40;
            layout.ry = 200;
            layout.width = 100;
            layout.height = 200;
            
            stickerView.layout = layout;
            [newModel.attaches.views addObject:stickerView];
            
        }
            break;
        case 12:
        {//添加贴图（视频）
            //移除已添加的特效
            if (newModel.attaches.views.count) {
                [newModel.attaches.views enumerateObjectsUsingBlock:^(__kindof BPMixView * _Nonnull obj, NSUInteger idx, BOOL * _Nonnull stop) {
                    if ([obj isKindOfClass:[BPMixVideoView class]]) {
                        [newModel.attaches.views removeObject:obj];
                    }
                }];
//                break;
            }
            NSString *fileName = @"video1.mp4";
            NSString *path = [[NSBundle mainBundle] pathForResource:fileName ofType:nil];
            NSString *relativePath = [NSString stringWithFormat:@"%@%@", BPMediaDirectory, fileName];
            
            NSString* fullPath = [NSString stringWithFormat:@"%@%@",NSHomeDirectory(), relativePath];
            
            if (![[NSFileManager defaultManager] fileExistsAtPath:fullPath]) {
                BOOL isSuccess = [[NSFileManager defaultManager] copyItemAtPath:path toPath:fullPath error:nil];
                if (!isSuccess) {
                    NSLog(@"");
                    return;
                }
            }
            BPMixMediaSource* source = [[BPMixMediaSource alloc] initWithSandboxPath:relativePath];
            BPMixVideoView *stickerView  = [[BPMixVideoView alloc]initWithSource:source];
            
            AVURLAsset * asset = [AVURLAsset assetWithURL:[NSURL fileURLWithPath:fullPath]];
            CMTime   time = [asset duration];
            int duration = ceil(time.value * 1000/time.timescale);
            
            stickerView.mediaDuration = duration;    // 视频时长
            
            stickerView.mType = Mix_Video;
            stickerView.attachTime = 0;
            stickerView.mediaDuration = -1; //一直显示
//            stickerView.mediaDuration = 2000; //2s
            
            BPMixLayout *layout = [[BPMixLayout alloc]init];
            layout.rx = 40 + 220;
            layout.ry = 50;
            layout.width = 200;
            layout.height = 200;
            
            stickerView.layout = layout;
            [newModel.attaches.views addObject:stickerView];
            
        }
            break;
        case 13:
        {//清空所有特效
             newModel = [self.windowModel copy];
             self.model = newModel;
        }
            break;
            
        default:
            break;
    }
    
    //更新播放器数据
    [self.videoPlayer updatePlayerData: newModel];
    [self play];
}

///中文转拼音
- (NSString *)transChineseStringToPingyin:(NSString *)szString {
    if ([szString length]) {
        NSMutableString *ms = [[NSMutableString alloc] initWithString:szString];
        if (CFStringTransform((__bridge CFMutableStringRef)ms, 0, kCFStringTransformMandarinLatin, NO)) {}
        if (CFStringTransform((__bridge CFMutableStringRef)ms, 0, kCFStringTransformStripDiacritics, NO)) {}
        return [ms stringByReplacingOccurrencesOfString:@" " withString:@""];
    }
    return @"";
}

- (void)saveImageFromFilePath:(NSString *)filePath completionHandler:(void(^)(BOOL success))completionBlock
{
    [[PHPhotoLibrary sharedPhotoLibrary] performChanges:^{
            
         //写入图片到相册
         [PHAssetChangeRequest creationRequestForAssetFromImageAtFileURL:[NSURL fileURLWithPath:filePath]];
            
            
     } completionHandler:^(BOOL success, NSError * _Nullable error) {
            
         NSLog(@"success = %d, error = %@", success, error);
         completionBlock(success);
            
    }];
}

#pragma mark -------视频保存完毕的回调--------
- (void)video:(NSString *)videoPath didFinishSavingWithError:(NSError *)error contextInfo:(void *)contextInf{
    if (error) {
        NSLog(@"保存视频过程中发生错误，错误信息:%@",error.localizedDescription);
    }else{
        NSLog(@"视频保存成功.");
    }
}

- (void)dealloc {
    [self.videoPlayer stop];
}


@end
