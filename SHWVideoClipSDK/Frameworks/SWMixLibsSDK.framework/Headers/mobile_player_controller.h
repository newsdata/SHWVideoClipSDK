/*
 * Copyright (c) 2019 xhzy
 *
 */

#ifndef MOBILE_PLAYER_CONTROLLER_H_
#define MOBILE_PLAYER_CONTROLLER_H_

#include "video_frame.h"
#include "audio_frame.h"

namespace mobile {

struct Text_t {
    std::string text;
    std::string font;
    int         fontSize;
    std::string fontColor;
    int         strokeWidth = 0;     // 描边宽度
    float       strokeAlpha = 1;     // 描边透明度
};

struct Subtitle_t {
    int64_t               startTime;
    int64_t               endTime;
    Text_t                title;
    Text_t                subtitle;
    std::string           bgColor;
    std::string           shadowColor;
    mix::engine::Layout_t layout;
    bool                  shadow;
    int                   topPadding = 0;      // 文字距离字幕矩形框顶
    int                   leftPadding = 0;     // 文字距离字幕矩形框左
    int                   linePadding = 0;     // 两行文字距离
    int                   shadowPaddingX = 0;  // 阴影矩形框距离字幕矩形框x
    int                   shadowPaddingY = 0;  // 阴影矩形框距离字幕矩形框y
    std::string           strImageUrl;
    mix::engine::Layout_t tImgaeLayout;
};
typedef std::list<Subtitle_t> Subtitles_t;

enum PlayStat_e {
    PlayStat_None,
    PlayStat_Play,
    PlayStat_Pause,
    PlayStat_Stop
};

class MobileControlable {
public:
    virtual ~MobileControlable() {}

    virtual void onPlay() = 0;
    virtual void onPause() = 0;
    virtual void onStop() = 0;
};

class MobileVideoRenderable : public MobileControlable {
public:
    virtual ~MobileVideoRenderable() {}

    virtual void renderVideo(VideoFrame *frame) = 0;
};

class MobileAudioRenderable : public MobileControlable {
public:
    virtual ~MobileAudioRenderable() {}

    virtual void renderAudio(AudioFrame *frame) = 0;
};

class MobilePlayerController {
public:
    virtual ~MobilePlayerController() {}

    virtual MobileVideoRenderable* getVideoRenderable() = 0;
    virtual MobileAudioRenderable* getAudioRenderable() = 0;

    /**
     * 播放器初始化
     *
     * @param sink 视频回调指针
     * @param sink2 音频回调指针
     * @param config 配置项
     * @param mediaViews 视频展示项
     * @param audios 音频项
     */
    virtual bool init(MobileVideoRenderable *sink, MobileAudioRenderable* sink2,
                      mix::engine::Config_t* config,
                      mix::engine::MediaViews_t* mediaViews,
                      mix::engine::Audios_t* audios,
                      Subtitles_t* subtitles) = 0;

    /** 缓存帧数据用于快速查找上一帧 */
    virtual void cacheFrames() = 0;

    /** 播放 */
    virtual void play(bool cycle = true) = 0;

    /** 暂停 */
    virtual void pause() = 0;

    /** 停止 */
    virtual void stop() = 0;

    /** seek到指定位置，单位毫秒
     *
     * seek超出了视频选段时长时，有可能取不到指定时间的画面，需要先进行reset将视频选段置为整个视频时长
     */
    virtual bool seek(int64_t timeInMS) = 0;

    /** 获取当前播放位置，单位毫秒 */
    virtual int64_t curPosition() = 0;

    /** 获取视频总时长，单位毫秒 */
    virtual int64_t totalDuration() = 0;

    /** 获取当前播放状态 */
    virtual PlayStat_e state() = 0;

    /**
     * 重新设置配置项，并从当前位置继续开始
     *
     * @param curPosition 当前播放位置（deprecated）
     * @param config 配置项
     * @param mediaViews 视频展示项
     * @param audios 音频项
     */
    virtual void reset(int64_t curPosition,
                       mix::engine::Config_t* config,
                       mix::engine::MediaViews_t* mediaViews,
                       mix::engine::Audios_t* audios,
                       Subtitles_t* subtitles) = 0;

    /**
     * 合成/取消合成视频（deprecated）
     */
    virtual bool combine(const char* outFile,
                         mix::engine::Config_t* config,
                         mix::engine::MediaViews_t* mediaViews,
                         mix::engine::Audios_t* audios,
                         Subtitles_t* subtitles) = 0;
    virtual void cancelCombine() = 0;

    /** 获取上/下一帧数据 */
    virtual void preFrame() = 0;
    virtual void nextFrame() = 0;

};

MobilePlayerController* NewMobilePlayerController();

int GetLinesize(int w, int h);

/** 获取音频音量 */
void GetAudioVolume(MobileAudioRenderable* sink, const char* path);

/** 计算音频 */
double CalcVolume(AudioFrame* frame);

/**
 * 截图（deprecated）
 *
 * @param sink 截图数据回调指针
 * @param path 视频路径
 * @param start 开始时间，单位ms
 * @param end 结束时间，单位ms，结束时需要再取一张截图
 * @param w 图片宽（可能需要进行裁剪）
 * @param h 图片高
 * @param interval 截图时间间隔，单位ms，默认1s一张截图
 * @return 0 success; other failed
 *
 */
int VideoCapture(MobileVideoRenderable* sink,
                 const char* path,
                 int64_t start, int64_t end,
                 int w, int h,
                 int64_t interval = 1000);

/**
 * 截图（允许多线程调用）
 *
 * @return
 */
void* CreateVideoCaptureHandle();
int VideoCapture(void* handle, MobileVideoRenderable* sink,
                 const char* path,
                 int64_t start, int64_t end,
                 int w, int h,
                 int64_t interval = 1000);
void DestroyVideoCaptureHandle(void* handle);

/**
 * 创建音频编码句柄
 *
 * @param file 音频编码文件名
 */
void* CreateAudioEncodeHandle(const char* file);

/**
 * 音频编码
 *
 * @param handle 音频编码句柄
 * @param data 原始PCM数据
 * @param len 原始PCM数据长度
 * @return 编码后数据长度
 */
int AudioEncode(void* handle, uint8_t* data, int64_t len);

/**
 * 销毁音频编码句柄
 */
void DestroyAudioEncodeHandle(void* handle);

/**
 * 生成片尾视频（允许多线程调用）
 *
 * @return
 */
void* CreateTailVideoHandle();
int TailVideo(void* handle,
              const char* bgColor,
              int w, int h, int64_t duration, const char* outName,
              const char* imgPath,
              mix::engine::Layout_t* layout);
void DestroyTailVideoHandle(void* handle);

/**
 * 生成视频
 *
 * @return
 */
void* CreateGenerateVideoHandle();
int GenerateVideo(void* handle,
                  const char* outFile,
                  mix::engine::Config_t* config,
                  mix::engine::MediaViews_t* mediaViews,
                  mix::engine::Audios_t* audios,
                  Subtitles_t* subtitles);
void CancelGenerateVideo(void* handle);
void DestroyGenerateVideo(void* handle);

void MixMobileFinish();

}  // namespace mobile

#endif  // MOBILE_PLAYER_CONTROLLER_H_
