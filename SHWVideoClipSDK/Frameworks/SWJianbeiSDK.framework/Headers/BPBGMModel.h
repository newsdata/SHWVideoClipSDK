/*! 头文件信息
 
 @header BPBGMModel.h
 
 @abstract 头文件基本描述
 
 @author Creat by 段桥 2019/8/8
 
 @version 1.00 2019/8/8 Creation(此文档的版本信息)
 
 Copyright © 2019 Xin Hua Zhi Yun. All rights reserved.
 
 */
#import "RLMObject.h"
#import "BPBaseRealmObject.h"

@class BPNetBGMDataModel;
@class BPNetBGMDataDetailModel;

static NSString * _Nonnull const PHONE_AUDIO = @"视频提取音乐";

NS_ASSUME_NONNULL_BEGIN

@interface BPBGMModel : BPBaseRealmObject
/** 音频标题 */
@property NSString *bgmTitle;
/** 音频路径 */
@property NSString *pathName;
/** 添加时间,后续可能按照这个时间排序显示 */
@property NSDate *createTime;
/** 音频ID 主要用于网络下载音频管理，需要使用时，先判断ID是否在数据存在，存在->使用缓存音频，不存在->下载音频 */
@property NSString *bgmID;
/** 作者 phone:本地生成 net网络下载*/
@property NSString *author;
/** 拓展名 目前已知：.m4a .mp3*/
@property NSString *extensionName;
/** 文件类型  bgm:1 audio:2*/
@property NSInteger type;
/** 是否被使用  */
@property NSInteger isUse;
/** 是否删除 */
@property NSInteger isDelete;

+ (BPBGMModel *)translateFromNetBGMModel:(BPNetBGMDataDetailModel *)netBGMModel;

- (void)saveAudioModel:(BPBGMModel *)bgmModel;

+ (void)saveAudioModel:(BPBGMModel *)bgmModel;

- (void)refreshAudioModel:(BOOL)isUse;

- (void)refreshAudioDelete:(BOOL)isDelete;

@end


@interface BPNetBGMModel : NSObject

@property (nonatomic, strong) NSString *code;

@property (nonatomic, strong) BPNetBGMDataModel *data;

@property (nonatomic, assign) BOOL fail;

@property (nonatomic, strong) NSString *msg;

@property (nonatomic, strong) NSString *requestId;

@property (nonatomic, assign) BOOL success;

@end

@interface BPNetBGMDataModel : NSObject

@property (nonatomic, assign) NSInteger totalCnt;

@property (nonatomic, assign) NSInteger pageNo;

@property (nonatomic, assign) NSInteger pageSize;

@property (nonatomic, strong) NSMutableArray<BPNetBGMDataDetailModel*>*detail;

@end

@interface BPNetBGMDataDetailModel : NSObject

@property (nonatomic, strong) NSString *category;

@property (nonatomic, strong) NSString *categoryText;

@property (nonatomic, strong) NSString *componentName;

@property (nonatomic, strong) NSString *decorateName;

@property (nonatomic, strong) NSString *decorateType;

@property (nonatomic, strong) NSString *infoDescription;

@property (nonatomic, strong) NSString *sampleGifUrl;

@property (nonatomic, strong) NSString *samplePicUrl;

@property (nonatomic, strong) NSString *sampleVideoUrl;

@property (nonatomic, strong) NSString *source;

@property (nonatomic, strong) NSString *filePath;

@end

NS_ASSUME_NONNULL_END
