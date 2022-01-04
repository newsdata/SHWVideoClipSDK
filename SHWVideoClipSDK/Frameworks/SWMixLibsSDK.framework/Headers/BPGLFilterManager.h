//
//  BPGLFilterManager.h
//  SHWMixLibs
//
//  Created by Ray on 2020/1/2.
//  一个管理 filter 的工厂类单例，为了应用层能够直接拿到 filter 对象并对齐进行操作

#ifndef BPFilterManager_hpp
#define BPFilterManager_hpp

#include <stdio.h>
#include "BPGLFilter.h"

namespace ios {

class BPGLFilterManager {
    
public:
    
    static BPGLFilterManager *sharedInstance();
    
    void registerFilter(BPGLFilter *filter);
    
    void unregisterFilter(BPGLFilter *filter);
    
    BPGLFilter * getFilter();
    
private:
    
    BPGLFilterManager();
    
    static BPGLFilterManager *instance;
    
    std::list<BPGLFilter*> filterList;
};
    
}; // namespace ios

#endif
