//
//  BPEditDraftModel.h
//  BeiPaiVideoEditor
//
//  Created by yehot on 2019/7/24.
//  Copyright © 2019 Xin Hua Zhi Yun. All rights reserved.
//

#import "BPBaseRealmObject.h"
#import <SWMixLibsSDK/BPMixWindow.h>
#import "BPCameraDraftModel.h"

/// 草稿
@interface BPEditDraftModel : BPBaseRealmObject

#pragma mark - realm 表字段

/// 草稿的创建时间 (不需要修改)
@property NSDate* createTime;

/// 草稿的上一次编辑后的 保存时间
@property NSDate* lastModifyTime;

/// 草稿里视频片段的总时长： 毫秒
@property long fragmentTotalTime;
// fragmentTotalTime 字段可能没有及时更新，需要最新值要调用 getFragmentTotalTime
- (long)getFragmentTotalTime;

/// 片段数量
@property int fragmentCount;

/// 草稿名称（默认显示时间戳）
@property NSString* draftName;

/// 最后合成的视频文件名 （不需要修改）
@property NSString* outputFileName;
- (NSString *)getOuputFileFullPath;

/// 视频的编辑信息数据，转成的本地 JOSN 文件路径
@property NSString* draftJsonFileName;
- (NSString *)getDraftJsonFileFileFullPath;

/// 草稿 封面图（默认为空，需要在保存时更新）
@property NSString* coverImageName;
- (UIImage *)coverImage;
/// 草稿保存前，必须更新封面图
- (void)updateCoverImage;


#pragma mark - other

/**
 视频的编辑信息 model
 NOTE: (此数据 不会存入数据库； 只会存 model 转成 json 后的 json 文件路径)
 */
@property (nonatomic, strong) BPMixWindow *mixWindowModel;

/// 从 json 文件中反序列化
- (BPMixWindow *)loadMixWindowFromJsonFile;

/// 从数据库删除此条草稿时，删除对应缓存
- (BOOL)deleteCacheFile;

@end

