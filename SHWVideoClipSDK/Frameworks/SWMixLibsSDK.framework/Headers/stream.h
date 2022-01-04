/*
 * Copyright (c) 2018 xhzy
 *
 */

#ifndef FFMPEG_STREAM_H_
#define FFMPEG_STREAM_H_

#include "demuxer.h"
#include "decoder.h"
#include "video_renderer_algorithm.h"
#include "audio_resample.h"

namespace mix {
namespace ffmpeg {

enum StreamType_e {
    StreamType_Unknow,
    StreamType_Mp4,
    StreamType_Hls
};

enum MediaType_e {
    MediaType_None,
    MediaType_VideoPacket = 1 << 0,
    MediaType_AudioPacket = 1 << 1,
    MediaType_VideoFrame  = 1 << 2,
    MediaType_AudioFrame  = 1 << 3,
    MediaType_MediaPacket = MediaType_VideoPacket | MediaType_AudioPacket,
};

class Stream;
class StreamSink {
public:
    virtual int OnReadVideoFrame(Stream* handle, AVFrame* frame) {
        av_frame_free(&frame);
        return 0;
    }

    virtual int OnReadAudioFrame(Stream* handle, AVFrame* frame) {
        av_frame_free(&frame);
        return 0;
    }

    virtual int OnReadVideoPacket(Stream* handle, AVPacket* packet) {
        av_packet_free(&packet);
        return 0;
    }

    virtual int OnReadAudioPacket(Stream* handle, AVPacket* packet) {
        av_packet_free(&packet);
        return 0;
    }

    virtual ~StreamSink() {}
};

class Stream : public Demuxer,
               public DecoderSink,
               public VideoRendererAlgorithmSink,
               public AudioResampleSink {
public:
    Stream();
    virtual ~Stream();

    virtual bool  Open         (const char* url,
                                MediaType_e media_type,
                                StreamType_e stream_type,
                                float speed = 1.0);  // 打开流
    virtual void  Close        ();                   // 关闭流
    virtual void  SetSink      (StreamSink* sink);   // 设置回调指针
    virtual void  SetFps       (int fps);            // 设置fps
    virtual bool  SetTimeRange (int stream_index,
                                int64_t start_time,
                                int64_t stop_time,
                                bool seek);          // 设置时间区间
    virtual void  CloseAudioDecoder();
    virtual void  CloseVideoDecoder();

#ifdef FFMPEG_V3
    virtual int   ReadFrameEx  ();
#endif
    virtual bool  SeekFrame    (int stream_index,
                                int64_t seek,
                                MediaType_e type);  // Seek start_time为ns

    virtual void  OnVideoPacket(AVPacket* packet);
    virtual void  OnAudioPacket(AVPacket* packet);
    virtual void  OnReadOver(int tag);
    virtual void  OnReadOverFrame();
    virtual void  OnCheckDiscard();

    // 回调接口 FFmpegDecoderSink
    virtual int   OnDecodeFrame(Decoder* handle, AVFrame* frame);

    // 回调接口 VideoRendererAlgorithmSink
    virtual int   OnVideoRendererAlgorithmFrame(AVFrame* frame);
    virtual int   OnVideoRendererAlgorithmOver();

    // 回调接口 AudioResampleSink
    virtual int   OnAudioResampleFrame(AVFrame* frame);
    virtual int   OnAudioResampleOver();

protected:
    bool IsNeedAudioPacket();
    bool IsNeedVideoPacket();
    bool IsNeedAudioFrame();
    bool IsNeedVideoFrame();

    StreamSink*             m_pSink;
    Decoder*                m_pVideoDecoder;
    Decoder*                m_pAudioDecoder;
    VideoRendererAlgorithm* m_pVideoRendererAlgorithm;
    AudioResample*          m_pAudioResample;
    MediaType_e             m_eMediaType;
    StreamType_e            m_eStreamType;
    float                   m_fSpeed;
};

// 创建读句柄
Stream* FFmpegStreamOpen(const char *url, MediaType_e type, float speed = 1.0);

}  // namespace ffmpeg
}  // namespace mix

#endif  // FFMPEG_STREAM_H_
