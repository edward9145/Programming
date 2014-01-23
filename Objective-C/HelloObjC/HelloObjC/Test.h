//
//  Test.h
//  HelloObjC
//
//  Created by 赵 骥恒 on 14-1-18.
//  Copyright (c) 2014年 __MyCompanyName__. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface Test : NSObject
{
    int i;
}

@property int i;

+(void)print;
-(void)print:(NSString *)str;
-(void)printInt:(int)num;
@end
