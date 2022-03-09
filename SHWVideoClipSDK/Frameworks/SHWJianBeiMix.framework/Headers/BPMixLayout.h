//
//  BPMixLayout.h
//  BeiPaiVideoEditor
//
//  Created by yehot on 2019/7/22.
//  Copyright © 2019 Xin Hua Zhi Yun. All rights reserved.
//

#import <Foundation/Foundation.h>


// TODO: 有默认值待处理
@interface BPMixLayout : NSObject <NSCopying>

/**
 * 当前View左上角相对于所在父容器左上角的水平位置
 */
@property (nonatomic, assign) int rx;

/**
 * 当前View左上角相对于所在父容器左上角的垂直位置
 */
@property (nonatomic, assign) int ry;

/**
 * 当前View的宽度,-1表示自适应，使用view本身的宽度
 */
@property (nonatomic, assign) int width;

/**
 * 当前View的高度,-1表示自适应，使用View本身的高度
 */
@property (nonatomic, assign) int height;

/**
 * 当前View的坐标处理，默认为1，表示左上角坐标，一共支持9种坐标系，按九宫格展示
 *  默认 = 1
 */
@property (nonatomic, assign) int position;

/**
 * 当前View的透明度,0~100
 *  默认为100
 */
@property (nonatomic, assign) float refract;


/**
 * 位于九宫格哪个格子 (iOS端) 1~9
 *
 * 默认是 8 底部居中
 */
@property (nonatomic, assign) int ios_Position;

@end
