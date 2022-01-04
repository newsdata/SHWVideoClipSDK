/*
 * Copyright (c) 2018 xhzy
 *
 */

#ifndef UTIL_UTIL_H_
#define UTIL_UTIL_H_

#include <stdio.h>
#include <stddef.h>
#include <stdint.h>
#include <string>
#include <map>
#include <list>
#include "SkBitmap.h"
#include "mix.h"

#ifdef __APPLE__
#define MIX_WORK_TEMP "/tmp/mixWorkTemp/"
#elif defined MIX_IOS
#define MIX_WORK_TEMP "/Desktop/"
#elif defined MIX_ANDROID
#define MIX_WORK_TEMP "/sdcard/mixWorkTemp/"
#else
#define MIX_WORK_TEMP "/root/mixWorkTemp/"
#endif

#include "SkPaint.h"
#include "SkTextBlob.h"

namespace mix {
namespace base {

class MixUtil {
public:
    MixUtil() {}
    virtual ~MixUtil() {}

    static void Init();

    // 读文件
    static int ReadFile(const char *file, char **buf);

    // 分割字符串
    static std::list<std::string> Split(const std::string &str, const std::string &delim);

    // 解析k1=v1,k2=v2
    static std::map<std::string, std::string> ParseKV(const std::string &str);

    static void ReplaceAll(std::string &s, std::string const &t, std::string const &w);

    static int64_t GetUnixNano();

    static std::string DownlaodFile(std::string url);
    static std::string GetFileExt(std::string url);

    static void RemoveFile(std::string file);
    static int  RemoveDir(std::string dirPath);
    static std::list<std::string> GetFilesInDir(std::string dirPath);

    static void ToPictureFromBitmap (SkBitmap bitmap, const char* name);
    static void ToPictureFromAVFrame(void* frame, const char* name);
    static void ToPictureFromData   (uint8_t* data, int w, int h, int linesize, const char* name);

    static bool LoadImage(SkBitmap& bitmap, const char* path);

    static int Atoi(const char* k, int v);
    static int Ftoi(float k, int v);

    static int GetVideoFPS(std::string url);
    static bool GetMediaInfo(std::string url, engine::MediaInfo_t* info);
    static std::string GetMediaTypeName(std::string url);

    static long ColorStrToL(std::string s);
    static void CalcPaddingOffset(const mix::engine::Layout_t* tLayout,
                                  int nW, int nH,
                                  int* nDrawX, int* nDrawY,
                                  int rows = 3, int cols = 3);

    static void CalcPaddingOffset2(const mix::engine::Layout_t* tLayout,
                                   int* nDrawX, int* nDrawY);

    static int GreatestCommonDivisor(int a,int b);
    static int FFmpegGetLinesize(int w);
    static double FFmpegCalcVolume(uint8_t** data);

    /////////////////////////////////////////
    // 参数检查
    static void CheckMediaInfo(const engine::MediaInfoPara_t& info);
    static void CheckConfig(const engine::Config_t& info);
    static void CheckMediaView(const engine::MediaView_t& info);
    static void CheckAudio(const engine::Audio_t& info);

    /////////////////////////////////////////

    static void SetImageAlpha(uint8_t *src, int linesize, int h, float alpha, uint8_t *dst);

    static int64_t UnusualIndexJudge(std::vector<engine::MosaicTraceRect_t>& tRects, int64_t nFragmentStartTime, int64_t nFragmentEndTime);

    static int64_t FindStartIndex(std::vector<engine::MosaicTraceRect_t>& tRects, int64_t nFragmentStartTime, int64_t nFragmentEndTime);
    static int64_t FindIndex(std::vector<engine::MosaicTraceRect_t>& tRects, int64_t nPts, int64_t nFragmentStartTime, int64_t nFragmentEndTime);

    static void BuildTextBlob(SkTextBlobBuilder* builder, SkPaint& paint, const char text[], SkScalar x, SkScalar y);
    static int GetTextList(SkPaint& p, SkPaint& default_p, std::string& text, std::list<std::string>* texts, SkTextBlobBuilder* builder = nullptr);

    static void MixGetFontPath(void (*SetFontPathWithName)(const std::string fontName, std::string& fontPath));
    static std::string SetFontPath(std::string path);
};

}  // namespace base
}  // namespace mix

#endif  // UTIL_UTIL_H_
