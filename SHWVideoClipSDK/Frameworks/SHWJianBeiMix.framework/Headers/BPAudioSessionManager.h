//
//  BPAudioSessionManager.h
//  JianBei
//
//  Created by Ray on 2019/11/28.
//  Copyright © 2019 Xin Hua Zhi Yun. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef void(^interruptionBlock)(NSInteger interruptionAction);  // 1: began 0: end

@interface BPAudioSessionManager : NSObject
@property (nonatomic, assign) Float64   sampleRate;
@property (nonatomic, assign) NSInteger outputChannels;
@property (nonatomic, assign) UInt32    preffereOutputChannels;
@property (nonatomic, assign) Float32   outputVolume;
@property (nonatomic, assign) BOOL      activated;

@property (nonatomic, copy) interruptionBlock interruptionBlock;

- (BOOL)activeAudioSession;

- (BOOL)deactiveAudioSession;

@end

NS_ASSUME_NONNULL_END
