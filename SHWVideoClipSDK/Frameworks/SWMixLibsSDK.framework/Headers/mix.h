/*
 * Copyright (c) 2018 xhzy
 *
 */

#ifndef ENGINE_DATASTRUCT_H_
#define ENGINE_DATASTRUCT_H_

#include <stdio.h>
#include <stddef.h>
#include <stdint.h>
//#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <map>
#include <SkPoint.h>
#include <SkBlendMode.h>

namespace mix {
namespace engine {

#define MIX_API = 0;

///错误码
#define MIX_ERR_ISNULL_OR_NO               -1    // 入参为空或者无
#define MIX_ERR_INVAILD_FRAGMENT_STARTTIME -2    // 无效的fragmentStartTime
#define MIX_ERR_INVAILD_FRAGMENT_ENDTIME   -3    // 无效的fragmentEndTime
#define MIX_ERR_INVAILD_STARTTIME          -4    // 无效的startTime
#define MIX_ERR_INVAILD_ENDTIME            -5    // 无效的endTime
#define MIX_ERR_INVAILD_SPEED              -6    // 无效的speed
#define MIX_ERR_INVAILD_MEDIAURL           -7    // 无效的mediaUrl
#define MIX_ERR_INVAILD_MEDIATYPE          -8    // 无效的media type
#define MIX_ERR_INVAILD_CONFIG             -9    // 无效的config
#define MIX_ERR_UNSUPPORT_OUTFORMAT        -10   // 不支持的输出格式
#define MIX_ERR_APPLICATION_EXCEPTION      -11   // 应用异常
#define MIX_ERR_PARSE_JSON                 -12   // json解析错误
#define MIX_ERR_OPEN_URL_FAILD             -13   // 打开url失败
#define MIX_ERR_INVAILD_LAYOUT_WH          -14   // 无效的layout宽高
#define MIX_ERR_RECALC_MEDIAVIEW           -15   // 重新计算全局mediaView错误
#define MIX_ERR_UNSUPPORT_FPS              -16   // 不支持的fps
#define MIX_ERR_INVAILD_MOSAIC_TIME_STAMP  -17   // mosaic trace的输入时间戳无效
#define MIX_ERR_INVAILD_FRAGMENT_TIME      -18   // 错误的fragment时间戳，导致无法找到有效的ts文件
#define MIX_ERR_M3U8_DOWNLOAD_FAILED       -19   // m3u8文件下载失败
#define MIX_ERR_INVALID_CONTOUR_COORDINATE -20   // 描边轮廓的坐标无效

// 自定义退出
static char gMixErrStr[][1024] = {
    "No ERROR",
    "MIX_ERR_ISNULL_OR_NO",
    "MIX_ERR_INVAILD_FRAGMENT_STARTTIME",
    "MIX_ERR_INVAILD_FRAGMENT_ENDTIME",
    "MIX_ERR_INVAILD_STARTTIME",
    "MIX_ERR_INVAILD_ENDTIME",
    "MIX_ERR_INVAILD_SPEED",
    "MIX_ERR_INVAILD_MEDIAURL",
    "MIX_ERR_INVAILD_MEDIATYPE",
    "MIX_ERR_INVAILD_CONFIG",
    "MIX_ERR_UNSUPPORT_OUTFORMAT",
    "MIX_ERR_APPLICATION_EXCEPTION",
    "MIX_ERR_PARSE_JSON",
    "MIX_ERR_OPEN_URL_FAILD",
    "MIX_ERR_INVAILD_LAYOUT_WH",
    "MIX_ERR_RECALC_MEDIAVIEW",
    "MIX_ERR_UNSUPPORT_FPS",
    "MIX_ERR_INVAILD_MOSAIC_TIME_STAMP",
    "MIX_ERR_INVAILD_FRAGMENT_TIME",
    "MIX_ERR_M3U8_DOWNLOAD_FAILED",
};

#if defined(MIX_MAC) || defined(MIX_LINUX)
#define MIX_EXIT(code) \
    LOG(INFO) << "FATAL ERROR:code=" << code << "," << mix::engine::gMixErrStr[-code]; \
    exit(code);
#else
#define MIX_EXIT(code) \
    LOG(INFO) << "FATAL ERROR:code=" << code << "," << mix::engine::gMixErrStr[-code];
#endif

#define DELETE_CLASS(cls)      if (cls) { delete cls; cls = nullptr; }

#define EPS 1e-6
#define FLOAT_EQ(x, y)  (x - y >= -EPS && x - y <= EPS)

///结构体
typedef std::list<std::string> ListString;

struct Config_t {
    int     nSampleRate;        // 采样率
    int     nFPS;               // 帧率
    int     nWidth;             // 视频宽度
    int     nHeight;            // 视频高度
    int64_t nEndTime;           // 当前片段在最终总视频的结束时间，单位为ns
    int64_t nStartTime;         // 当前片段在最终总视频的开始时间，单位ns
    int64_t nBitRate;           // 码率，默认为0不进行限制
    int64_t nCutStartTime;      // 支持工程片段
    int64_t nCutEndTime;        //
    int     nResolutionWidth;   // 原始宽
    int     nResolutionHeight;  //
    int64_t nDuration;          // 总时长
    bool    bPlayTransition = true;  // mobile 是否播放转场

    std::string strDynamicLayoutInfoUrl;  // 所有mosaictrace的跟踪路径数据
};

struct MosaicTraceRect_t {
    int64_t nTimeStamp;
    int nX;
    int nY;
    int nWidth;
    int nHeight;
};

struct Layout_t {
    int nCfgWidth;       // 配置输出视频宽度
    int nCfgHeight;      // 配置输出视频高度
    int nX;              // 当前View左上角相对于所在父容器左上角的水平位置
    int nY;              // 当前View左上角相对于所在父容器左上角的垂直位置
    int nWidth;          // 当前View的宽度
    int nHeight;         // 当前View的高度
    int nPosition;       // 九宫格
    int nRefract = 100;  // 当前View的透明度,0~100，默认为100

    int64_t nStartTime;               // mosaic相对于当前片段的开始时间
    std::vector<MosaicTraceRect_t> tMosaicTraceRects;  // 马赛克跟踪数据
};

enum VideoFilterType_e {
    // 新增枚举类型，枚举值往后追加，已有的不能变动（和 移动端保持一致）
    VFT_Unknow          = 0,
    VFT_Crop            = 1,
    VFT_OpenGL          = 2,
    VFT_Delogo          = 3,
    VFT_Mosaic          = 4,
    VFT_MosaicTrace     = 5,
    VFT_DelogoTrace     = 6,
    VFT_Lookup          = 7,
    VFT_Film            = 8,        // 大片
    VFT_ColorTone       = 9,        // 调色
    VFT_GreenCurtain    = 10,
    VFT_ZoomIn          = 11,       // 放大
    VFT_ZoomOut         = 12,       // 缩小
    VFT_ZoomLeft        = 13,       // 左移
    VFT_ZoomRight       = 14,       // 右移
    VFT_ZoomUp          = 15,       // 上移
    VFT_ZoomDown        = 16,       // 下移
    VFT_TailZoomIn      = 17,       // 片尾放大
    VFT_FaceZoom        = 18,       // 人脸放大
    VFT_PictureTrace    = 19,       // 贴图跟踪
    VFT_AutoReFrame     = 20,       // 自动裁剪
    VFT_ObjectStroke    = 21,       // 描边
    VFT_CutCorner       = 22        // 主副轴拼接
};

struct VideoFilter_t {
    VideoFilterType_e eType;         //
    std::string       strDataUrl;
    std::string       strGLSL;       //
    std::string       strImgPath;    //
    std::string       strBgColor;    // 绿幕颜色
    int64_t           nDuration;     //
    int64_t           nOffset;       //
    float             fX;            // 当name为crop时，为比例值
    float             fY;            // 当name为crop时，为比例值
    float             fW;            // 当name为crop时，为比例值
    float             fH;            // 当name为crop时，为比例值
    int64_t           nStartTime;    //
    float             fTemperature;  // 色温
    float             fSaturation;   // 饱和度
    float             fExposure;     // 曝光度
    float             fContrast;     // 对比度
    std::vector<SkPoint> skPoints;    // 描边数据
    int               nCornerNum;    // 裁剪方向
    float             fSlope;        // 裁剪斜率
    float             fIntensity;
};
typedef std::list<VideoFilter_t> VideoFilters_t;

enum TransitionType_e {
    TransitionType_Head,    // 转场加在切片头
    TransitionType_Tail,    // 转场加在切片尾
    TransitionType_Unknow   // 未知
};

struct Transition_t {
    int64_t          nDuration;   // 转场时长，单位ns
    int64_t          nOffset;     // 转场时长，单位ns
    TransitionType_e eType;       // 转场类型
    void*            pTransView;  // 进行转场的对象(View_t*)
    std::string      strGLSL;     // glsl文件路径
};
typedef std::vector<Transition_t> Transitions_t;

// video元素可能是gif、picture或真正的video流
enum ElemType_e {
    ElemType_Video,         // video
    ElemType_Gif,           // gif
    ElemType_Picture,       // picture
    ElemType_SVG,           // svg
    ElemType_Mosaic,        //
    ElemType_MosaicTrace,   //
    ElemType_Delogo,        //
    ElemType_DelogoTrace,   //
    ElemType_Unknow         // 未知类型
};

// 定义缩放类型
enum VideoScaleType_e {
    VideoScaleType_Normal,   // 直接将原图片/视频缩放至目标宽高
    VideoScaleType_Blur,     // 缩放+模糊：将原图片/视频缩放至目标宽高，并进行模糊操作后与原图叠加
    VideoScaleType_Color     // 缩放+颜色背景：  将原图片/视频缩放至目标宽高，并加上颜色背景后与原图叠加
};

struct VideoScale_t {
    VideoScaleType_e eVideoScaleType;  // 缩放类型 NORMAL-直接缩放到目标宽高；
                                       //        BLUR-缩放到指定大小并高斯模糊,作为原图的背景
                                       //        COLOR-背景使用某个颜色值
    std::string      strBGColor;       // 缩放类型VideoScaleType_Color的背景颜色

};

struct View_t {
    int            nOpaque;            // 自定义
    ElemType_e     eType;              // view类型
    int64_t        nStartTime;         // 片段的起始时间，单位ns(时间轴上的时间)
    int64_t        nEndTime;           // 片段的结束时间，单位ns(-1表示未知)
    Layout_t       tLayout;            // 当前View的布局位置
    VideoScale_t   tVideoScale;        // 缩放  1、直接缩放到目标宽高  2、缩放到指定大小并高斯模糊,作为原图的背景  3、缩放到指定大小并加颜色背景

    std::string    strAnimation;       // 目前动画效果可以认为都是SVG字符串，
    VideoFilters_t tFilters;           // 滤镜效果
    Transitions_t  tTransitions;       // 转场效果
    int64_t        nVideoFadeInDuration;     // 淡入时长，单位ns
    int64_t        nVideoFadeOutDuration;    // 淡出时长，单位ns
    std::string    strDynamicLayoutKey;      // mosaic跟踪Key值
    //字体路径
    std::string    strFontPath;
};

struct Rotation_t {
    int nX;                      // 旋转中心点x
    int nY;                      // 旋转中心点y
    int nRotation;               // 旋转角度
    bool bInPreProcess = false;  // 是否在预处理中旋转
};

struct Mirror_t {
    bool bMirrorX;  // 水平镜像参数
    bool bMirrorY;  // 垂直镜像参数
};

struct Crop_t {
    int nW = 0;  // 0表示不进行裁剪
    int nH = 0;
    int nX = 0;
    int nY = 0;
};

struct MediaView_t {
    bool        bRmSound;            // 是否移除声音
    int64_t     nCutStartTs;         // 视频/图片剪切媒资中的起始位置，单位ns。
                                     // 用于计算转场/滤镜baseline
    int64_t     nFragmentStartTime;  // 该切片在该媒资的起始时间，单位ns
    int64_t     nFragmentEndTime;    // 该切片在该媒资的结束时间，单位ns，
                                     // 如果为-1，表示到该视频结束
    std::string strMediaUrl;         // 媒资的地址，一般存储在OSS上
    int         nZIndex;             // 绘制顺序，值越大，越晚绘制
    View_t      tView;               //
    Rotation_t  tRotation;           // 旋转参数
    Mirror_t    tMirror;             // 镜像参数
    Crop_t      tCrop;               // 裁剪参数
    float       fSpeed = 1;          // 速度
    bool        bRepeat = false;     // 是否重复播放
    bool        bPlayTransition = false;  // mobile 是否播放转场
    SkBlendMode eBlendMode = SkBlendMode::kSrcOver;

    std::string to_string() {
        std::string temp;
        temp += "{\"url\":\"" + this->strMediaUrl + "\",";
        temp += "\"nStartTime\":" + std::to_string(this->tView.nStartTime) + ",";
        temp += "\"nEndTime\":" + std::to_string(this->tView.nEndTime) + ",";
        temp += "\"nFragmentStartTime\":" + std::to_string(this->nFragmentStartTime) + ",";
        temp += "\"nFragmentEndTime\":" + std::to_string(this->nFragmentEndTime) + ",";
        temp += "\"fSpeed\":" + std::to_string(this->fSpeed) + ",";
        temp += "\"eType\":" + std::to_string(this->tView.eType) + ",";
        temp += "\"tCrop.nX\":" + std::to_string(this->tCrop.nX) + ",";
        temp += "\"tCrop.nY\":" + std::to_string(this->tCrop.nY) + ",";
        temp += "\"tCrop.nW\":" + std::to_string(this->tCrop.nW) + ",";
        temp += "\"tCrop.nH\":" + std::to_string(this->tCrop.nH) + ",";
        temp += "\"tRotation.nRotation\":" + std::to_string(this->tRotation.nRotation) + "}";
        return temp;
    }
};
typedef std::list<MediaView_t> MediaViews_t;

enum AudioFilterType_e {
    AFT_Unknow,
    AFT_LowVolume,  // 降低音量
};

struct AudioFilter_t {
    AudioFilterType_e eType;       // 类型
    int64_t           nStartTime;  // 开始时间，单位ns
    int64_t           nEndTime;    // 结束时间，单位ns
    int               nVolume;     // 分贝值
};
typedef std::list<AudioFilter_t> AudioFilters_t;

struct Audio_t {
    std::string    strMediaUrl;         // 媒资的地址，一般存储在OSS上
    int64_t        nFragmentStartTime;  // 该切片在该媒资的起始时间，单位ns
    int64_t        nFragmentEndTime;    // 该切片在该媒资的结束时间，单位ns，
                                        // 如果为-1，表示到该视频结束
    int64_t        nEndTime;            // 当前片段在最终总视频的结束时间，单位ns
    int64_t        nStartTime;          // 当前片段在最终总视频的开始时间，单位ns
    bool           bRepeat;             // 是否重复播放
    bool           bMute;               // 是否静音
    AudioFilters_t tFilters;            // 滤镜效果
    float          fVolume;             // 音量
    int64_t        nFadeInDuration;     // 淡入时长，单位ns
    int64_t        nFadeOutDuration;    // 淡出时长，单位ns
    float          fSpeed = 1;          // 速度

    std::string to_string() {
        std::string temp;
        temp += "{\"url\":\"" + this->strMediaUrl + "\",";
        temp += "\"nStartTime\":" + std::to_string(this->nStartTime) + ",";
        temp += "\"nEndTime\":" + std::to_string(this->nEndTime) + ",";
        temp += "\"nFragmentStartTime\":" + std::to_string(this->nFragmentStartTime) + ",";
        temp += "\"nFragmentEndTime\":" + std::to_string(this->nFragmentEndTime) + ",";
        temp += "\"fSpeed\":" + std::to_string(this->fSpeed) + ",";
        temp += "\"bRepeat\":" + std::to_string(this->bRepeat) + ",";
        temp += "\"fVolume\":" + std::to_string(this->fVolume) + "}";
        return temp;
    }
};
typedef std::list<Audio_t> Audios_t;

struct MediaInfo_t {
    int64_t nDuration;  // 时长 ns
    int     nFPS;       // 帧率
    int     nWidth;     // 宽
    int     nHeight;    // 高
};

// 定义视频格式
enum VideoFormat_e {
    VideoFormat_MP4,
    VideoFormat_FLV,
    VideoFormat_GIF,
    VideoFormat_JPG,
};

// 定义视频编码
enum VideoCodec_e {
    VideoCodec_H264,  // H264 codec
    VideoCodec_H265   // H265 codec
};

// 定义视频编码
enum AudioCodec_e {
    AudioCodec_AAC,  // AAC codec
    AudioCodec_MP3   // MP3 codec
};

// 定义H264编码器的预设选项preset - 调整编码速度和视频质量
enum VideoH264Preset_e {
    H264Preset_ultrafast,  // ffmpeg X264 ultrafast
    H264Preset_superfast,  // ffmpeg X264 superfast
    H264Preset_veryfast,   // ffmpeg X264 veryfast
    H264Preset_faster,     // ffmpeg X264 faster
    H264Preset_fast,       // ffmpeg X264 fast
    H264Preset_medium,     // ffmpeg X264 medium
    H264Preset_slow,       // ffmpeg X264 slow
    H264Preset_slower,     // ffmpeg X264 slower
    H264Preset_veryslow,   // ffmpeg X264 veryslow
    H264Preset_placebo     // ffmpeg X264 placebo
};

// 媒体类型定义
enum MediaType_e {
    Media_None  = 0,
    Media_Audio = 1 << 0,  // 音频媒体类型
    Media_Video = 1 << 1,  // 视频媒体类型
    Media_All   = Media_Audio | Media_Video
};

// 定义app的类型
enum AppType_e {
    AppType_Transcode,  // 转码合成类型
    AppType_Play        // 预览播放类型
};

enum AppMode_e {
    AppMode_Magic,
    AppMode_NodeMix,
    AppMode_Mobile
};

// 媒体信息参数
struct MediaInfoPara_t {
    MediaType_e       eType;              // 媒体流类型
    int               nFPS;               // 视频帧率
    int               nWidth;             // 视频宽度
    int               nHeight;            // 视频高度
    int64_t           nBPS;               // 视频码率
    int64_t           nEndTime;           // 当前片段在最终总视频的结束时间，即timeline的起始时间，单位ns
    int64_t           nStartTime;         // 当前片段在最终总视频的开始时间，即timeline的结束时间，单位ns
    VideoFormat_e     eVideoFormat;       // 视频封装格式
    VideoCodec_e      eVideoCodec;        // 视频编码格式
    int               nCrf;               // 值越大，输出文件越小(取值范围：0～51，不影响视觉效果的范围：17～28)；
    VideoH264Preset_e ePreset;            // 调整编码速度:越小的文件和越快的编码速度都会在不同程度上降低画质
    int               nSampleRate;        // 音频采样率
    AudioCodec_e      eAudioCodec;        // 音频编码格式
    char              szOutName[1024];    // 输出文件名
    int64_t           nCutStartTime;      // 支持工程片段
    int64_t           nCutEndTime;        //
    int               nResolutionWidth;   // 原始宽
    int               nResolutionHeight;  //
};

// 初始化接口体参数
void MixInitConfig(Config_t* cfg);
void MixInitLayout(Layout_t* cfg);
void MixInitVideoFilter(VideoFilter_t* cfg);
void MixInitTransition(Transition_t* cfg);
void MixInitVideoScale(VideoScale_t* cfg);
void MixInitView(View_t* cfg);
void MixInitRotation(Rotation_t* cfg);
void MixInitMirror(Mirror_t* cfg);
void MixInitCrop(Crop_t* cfg);
void MixInitMediaView(MediaView_t* cfg);
void MixInitAudioFilter(AudioFilter_t* cfg);
void MixInitAudio(Audio_t* cfg);
void MixInitMediaInfoPara(MediaInfoPara_t* cfg);

bool MixEngineInit();
void MixEngineFinish();

}  // namespace engine
}  // namespace mix

#endif  // ENGINE_DATASTRUCT_H_
