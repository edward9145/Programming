//
//  Test.m
//  HelloObjC
//
//  Created by 赵 骥恒 on 14-1-18.
//  Copyright (c) 2014年 __MyCompanyName__. All rights reserved.
//

#import "Test.h"

@implementation Test

@synthesize i;

+(void)print{
    NSLog(@"Test print");
}

-(void)print:(NSString *)str{
    NSLog(str);
}

-(void)printInt:(int)num{
    NSLog(@"%i", num);
}
@end
