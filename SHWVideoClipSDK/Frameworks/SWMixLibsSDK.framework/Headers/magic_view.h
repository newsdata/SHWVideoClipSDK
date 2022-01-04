//
// Created by Wenwu Sun on 2019-07-01.
//

#ifndef MAGIC_VIEW_H
#define MAGIC_VIEW_H

#include <string>

#ifdef MIX_IOS
#include "mix.h"
#include "mixUtil.h"
#else
#include "mix.h"
#include "mixUtil.h"
#endif


namespace mobile {

#define MAGIC_DEFAULT_SAMPLE_RATE 44100
#define SEC_TO_MILLI 1000
#define MILLI_TO_NANO 1000000

    
#pragma mark -

class MagicView {

public:
    MagicView(){};

    virtual ~MagicView(){};

    enum {
        GROUP = 0,
        VIDEO = 1,
        PICTURE = 2,
        TRANSITION = 3,
        GIF = 4,
        SUBTITLE = 5,
        SVG = 6
    };

    int type;
};

#pragma mark -

class MagicViewGroup : public MagicView {

public:
    MagicViewGroup() {
        type = MagicView::GROUP;
    };

    virtual ~MagicViewGroup() {
        DeInit();
        views.clear();
    };

    std::list<MagicView*> views;

private:
    void DeInit() {
#ifdef MIX_IOS
        if (!views.empty()) {
            auto item = views.begin();
            for (; item != views.end(); item++) {
                MagicView* view = *item;
                if (view) {
                    delete *item;
                }
            }
        }
#endif
    }
};

#pragma mark -

class Layout {
public:
    int rx = 0;
    int ry = 0;
    int width = 0;
    int height = 0;
    int position = 1;
    int refract = 100;
};

#pragma mark -

#pragma mark -

class Crop {
    public:
        int rx = 0;
        int ry = 0;
        int width = 0;
        int height = 0;
};

#pragma mark -

class Font {
public:
    /** 字幕文本 */
    std::string text;

    /** 字体 */
    std::string font;

    /** 字体大小 */
    int fontSize;

    /** 字体颜色 */
    std::string fontColor;

    /// 描边宽度
    int strokeWidth;
    
    /// 描边透明度
    float strokeAlpha;

    virtual ~Font() {
        text.clear();
        font.clear();
        fontColor.clear();
    }
};

#pragma mark -

class Filter {
public:
    std::string name;
    std::string options;

    ~Filter() {
        name.clear();
        options.clear();
    }

    void transVideoFilter(mix::engine::VideoFilter_t *info) {
        if (name == "delogo") {
            info->eType = mix::engine::VFT_Delogo;
        } else if (name == "crop") {
            info->eType = mix::engine::VFT_Crop;
        } else if (name == "mosaic") {
            info->eType = mix::engine::VFT_Mosaic;
        } else if (name == "lookup-retro"  ||  // 怀旧
                   name == "lookup-tasty"  ||  // 高雅
                   name == "lookup-waltz"  ||  // 华尔兹
                   name == "lookup-dreamy" ||  // 梦幻
                   name == "lookup-sunny"  ||  // 和煦
                   name == "lookup-west") {    // 西方
            info->eType = mix::engine::VFT_Lookup;
        } else if (name == "film") {           // 大片
            info->eType = mix::engine::VFT_Film;
        } else if (name == "ColorTone") {
            info->eType = mix::engine::VFT_ColorTone;
        } else if (name == "RemoveCurtain") {
            info->eType = mix::engine::VFT_GreenCurtain;
        } else if (name == "zoomIn") {
            info->eType = mix::engine::VFT_ZoomIn;
        } else if (name == "zoomOut") {
            info->eType = mix::engine::VFT_ZoomOut;
        } else if (name == "zoomLeft") {
            info->eType = mix::engine::VFT_ZoomLeft;
        } else if (name == "zoomRight") {
            info->eType = mix::engine::VFT_ZoomRight;
        } else if (name == "zoomUp") {
            info->eType = mix::engine::VFT_ZoomUp;
        } else if (name == "zoomDown") {
            info->eType = mix::engine::VFT_ZoomDown;
        } else {
            info->eType = mix::engine::VFT_OpenGL;
        }

        info->fX = 0;
        info->fY = 0;
        info->fW = 0;
        info->fH = 0;
        info->nStartTime = 0;
        info->nDuration = 0;
        info->nOffset = 0;
        info->strGLSL = name; // iOS端需要使用name来区别滤镜，所以这里传滤镜名字
        info->strImgPath = "";
        info->fTemperature = 0;
        info->fSaturation = 0;
        info->fExposure = 0;
        info->fContrast = 0;
        info->strBgColor ="";

        std::map<std::string, std::string> map = mix::base::MixUtil::ParseKV(options);
        std::map<std::string, std::string>::iterator iter;

        iter = map.find("x");
        if (iter != map.end()) {
            info->fX = atof(iter->second.c_str());
        }

        iter = map.find("y");
        if (iter != map.end()) {
            info->fY = atof(iter->second.c_str());
        }

        iter = map.find("width");
        if (iter != map.end()) {
            info->fW = atof(iter->second.c_str());
        }

        iter = map.find("height");
        if (iter != map.end()) {
            info->fH = atof(iter->second.c_str());
        }

        iter = map.find("startTime");
        if (iter != map.end()) {
            info->nStartTime = atof(iter->second.c_str()) * MILLI_TO_NANO;
        }

        iter = map.find("duration");
        if (iter != map.end()) {
            info->nDuration = atof(iter->second.c_str()) * MILLI_TO_NANO;
        }

        iter = map.find("offset");
        if (iter != map.end()) {
            info->nOffset = atof(iter->second.c_str()) * MILLI_TO_NANO;
        }

        iter = map.find("source");
        if (iter != map.end()) {
            info->strGLSL = iter->second;
        }

        iter = map.find("imgPath");
        if (iter != map.end()) {
            info->strImgPath = iter->second;
        }

        iter = map.find("temperature");
        if (iter != map.end()) {
            info->fTemperature = atof(iter->second.c_str());
        }

        iter = map.find("saturation");
        if (iter != map.end()) {
            info->fSaturation = atof(iter->second.c_str());
        }

        iter = map.find("exposure");
        if (iter != map.end()) {
            info->fExposure = atof(iter->second.c_str());
        }

        iter = map.find("contrast");
        if (iter != map.end()) {
            info->fContrast = atof(iter->second.c_str());
        }

        iter = map.find("bgColor");
        if (iter != map.end()) {
            info->strBgColor = iter->second;
        }

        iter = map.find("strImgPath");
        if (iter != map.end()) {
            info->strImgPath = iter->second;
        }

        iter = map.find("intensity");
        if (iter != map.end()) {
            info->fIntensity = atof(iter->second.c_str());
        }
    }
};

#pragma mark -

class Transition: public MagicView {
public :
    std::string name;
    int64_t duration;
    std::string options;

    Transition() {
        type = MagicView::TRANSITION;
    }

    ~Transition() {
        name.clear();
        options.clear();
    }
};

#pragma mark -

class MagicMediaView: public MagicView {

public:
    int64_t cutStartTs = 0;
    int64_t cutEndTs = -1;
    int64_t mediaDuration = 0;
    int64_t attachTime = 0;
    std::string mediaUrl;
    Layout *layout = nullptr;
    Crop* crop = nullptr;
    std::list<Filter*> filters;
    int rotation = 0; // 旋转角度，默认为0°
    bool isTail = false;
    int64_t videoFadeInDuration = 0; // 淡入时长
    int64_t videoFadeOutDuration = 0; // 淡出时长
    std::string scaleType;

    virtual ~MagicMediaView() {
        DeInit();
        filters.clear();
        mediaUrl.clear();
        scaleType.clear();
    };
    MagicMediaView() {
        Init();
    };
    
private:
    void Init() {
#ifdef MIX_IOS
//        layout = new Layout();
//        crop = new Crop();
#endif
    }
    
    void DeInit() {
#ifdef MIX_IOS
        if (layout) {
            delete layout;
        }
        if (crop) {
            delete crop;
        }
        if (!filters.empty()) {
            auto item = filters.begin();
            for (; item != filters.end(); item++) {
                Filter* view = *item;
                if (view) {
                    delete *item;
                }
            }
        }
#endif
    }
};


#pragma mark -

class MagicVideoView: public MagicMediaView {

public:
    MagicVideoView() {
        type = MagicView::VIDEO;
    }
    virtual ~MagicVideoView(){};

    bool rmSound = false;
    double speed = 1.0;
    float volume = 1.0;
    int64_t volumeFadeInDuration = 0;
    int64_t volumeFadeOutDuration = 0;
};

    
#pragma mark -

class MagicImageView: public MagicMediaView {

public:
    MagicImageView() {
        type = MagicView::PICTURE;
    }
    virtual ~MagicImageView(){};

};


#pragma mark -

class MagicGifView: public MagicMediaView {

public:
    MagicGifView() {
        type = MagicView::GIF;
    }
    virtual ~MagicGifView(){};

};

class MagicSvgView : public MagicMediaView {
public:
    MagicSvgView() {
        type = MagicView::SVG;
    }

    //字体路径
    std::string fontPath;

    virtual ~MagicSvgView(){};
};

#pragma mark -

class SubtitleView: public MagicView {

public:
    /** 字幕切入时间，单位ms */
    int64_t attachTime = 0L;

    /** 字幕切出时间，单位ms */
    int64_t detachTime = -1L;

    /** 标题字体 */
    Font* titleFont = nullptr;

    /** 子标题字体 */
    Font* subFont = nullptr;

    /** 背景颜色 */
    std::string bgColor;

    /** 字幕布局位置 */
    Layout* layout = nullptr;

    /** 背景阴影 */
    bool shadow = false;

    /** 阴影颜色 */
    std::string shadowColor;

    /** 图片Url路径 */
    std::string strImageUrl;

    /** 图片布局位置 */
    Layout* tImageLayout;

    int topPadding = 0;      // 文字距离字幕矩形框顶
    int leftPadding = 0;     // 文字距离字幕矩形框左
    int linePadding = 0;     // 两行文字距离
    int shadowPaddingX = 0;  // 阴影矩形框距离字幕矩形框x
    int shadowPaddingY = 0;

    SubtitleView() {
        Init();
        type = MagicView::SUBTITLE;
    }

    virtual ~SubtitleView() {
        DeInit();
        bgColor.clear();
    }
    
private:
    void Init() {
#ifdef MIX_IOS
//        titleFont = new Font();
//        subFont = new Font();
//        layout = new Layout();
#endif
    }
    
    void DeInit() {
#ifdef MIX_IOS
        if (titleFont) {
            delete titleFont;
        }
        if (subFont) {
            delete subFont;
        }
        if (layout) {
            delete layout;
        }
#endif
    }
};

}

#endif //MAGIC_VIEW_H
