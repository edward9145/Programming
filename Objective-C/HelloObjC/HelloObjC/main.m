//
//  main.m
//  HelloObjC
//
//  Created by 赵 骥恒 on 14-1-18.
//  Copyright (c) 2014年 __MyCompanyName__. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "Test.h"

void data_type(){
    NSLog(@"%i", YES);
    
    short s = 32768 - 1;
    unsigned short us = 32768*2 - 1;
    
    NSLog(@"%i", s);        
    NSLog(@"%u", us);
    
    int i = 2147483648 - 1;
    unsigned int ui = 2147483648*2 - 1;
    
    NSLog(@"%i", i);        
    NSLog(@"%u", ui);
    
    long l = 4294967296 - 1;
    unsigned long ul = 4294967295;
    
    NSLog(@"%ld", l);
    NSLog(@"%lu", ul);
    
    NSLog(@"%#x", i);
    NSLog(@"%#x", ui);
}

void test_obj(){
    [Test print];
    
    Test *test = [Test new];
    [test print:@"test print"];
    [test setI:-1];
    [test printInt:test.i];
}

void foundation_obj(){
    
    NSNumber *num = [NSNumber numberWithChar:'k'];
    NSLog(@"%c", [num charValue]);
    
    NSString *str = @"Foundation/NSString";
    NSLog(@"%@", str);
    
    NSString *imported = [NSString stringWithFormat:@"%@ has been imported", str];
    NSLog(@"%@", imported);
    
    NSString *import = [@"#import " stringByAppendingString:str];
    import = [import uppercaseString];
    NSLog(@"%@", import);
    
    NSMutableArray *city = [NSMutableArray 
                            arrayWithObjects:@"Beijing", @"Shanghai", @"Guangdong", nil];
    [city addObject:@"Tianjin"];
    [city insertObject:@"ChongQin" atIndex:3];
    for(int i=0; i<[city count]; i++){
        NSLog(@"%i %@", i, [city objectAtIndex:i]);
    }
    
    
    NSString *B = @"B";
    NSString *S = @"S";
    NSString *G = @"G";
    
    NSMutableDictionary *dict = [NSMutableDictionary 
                                 dictionaryWithObjectsAndKeys:@"Beijing", B, @"Shanghai", S, nil];
    [dict setValue:@"GuangDong" forKey:G];
    [dict setObject:@"GuangZhou" forKey:G];
    NSLog(@"%@ -> %@", B, [dict objectForKey:B]);
    NSLog(@"%@ -> %@", G, [dict objectForKey:G]);
    NSLog(@"%@", dict);
    
    NSMutableSet *set = [NSMutableSet setWithObjects:@"Tokyo", @"Nara", @"Tsukuba", @"Osaka", nil];
    NSMutableSet *setJapan = [NSMutableSet setWithObjects:@"Tokyo", @"Sapporo", nil];
    [set unionSet:setJapan];
    NSLog(@"%@", set);
    
    NSMutableSet *setCity = [NSMutableSet setWithArray:city];
    NSLog(@"%@", setCity);
}

void file(){
    NSFileManager *fm = [NSFileManager defaultManager];
    NSString *path = [fm currentDirectoryPath];
    NSLog(@"%@", path);
    
    NSString *desktop = @"/Users/bigmonkey815/Desktop/";
    NSString *filetxt = @"file.txt";
    NSString *filename = [desktop stringByAppendingString:filetxt];
    if([fm fileExistsAtPath:filename] == YES)
        NSLog(@"%@ existed.", filename);
    NSLog(@"%@", [fm fileAttributesAtPath:filename traverseLink:YES]);
    
    [fm copyItemAtPath:filename toPath:[desktop stringByAppendingString:@"temp/file.txt"] error:nil];
    
    NSData *filecontent = [fm contentsAtPath:filename];
    NSLog(@"%i %@", [filecontent length], filecontent);
    
    NSString *filestr = [NSString stringWithContentsOfFile:filename 
                                                  encoding:NSUTF8StringEncoding error:nil];
    NSLog(@"%@", filestr);
    
    NSMutableString *filestrProc = [NSMutableString stringWithFormat:@"%@\n%@", filestr, [filestr uppercaseString]];
    NSLog(@"%@", filestrProc);
    NSString *fileprocname = [desktop stringByAppendingString:@"fileproc.txt"];
    [fm createFileAtPath:fileprocname contents:[filestrProc dataUsingEncoding:NSUTF8StringEncoding] attributes:nil];
}

void folder(){
    NSFileManager *fm = [NSFileManager defaultManager];
    NSString *desktop = @"/Users/bigmonkey815/Desktop/";
    NSDirectoryEnumerator *dirEnum = [fm enumeratorAtPath:desktop];
    NSString *path;
    while((path = [dirEnum nextObject]) != nil){
        NSLog(@"%@", path);
    }
    
    NSArray *dirArray = [fm directoryContentsAtPath:desktop];
    for(path in dirArray){
        NSLog(@"%@", path);
    }
}

void process(){
    NSProcessInfo *proc = [NSProcessInfo processInfo];
    int pid = [proc processIdentifier];
    NSLog(@"%@ %i", proc, pid);
    NSString *host = [proc hostName];
    NSLog(@"%@", host);
    NSString *sysinfo = [proc operatingSystemVersionString];
    NSLog(@"%@", sysinfo);
}

int threadPrint(int x){
    NSLog(@"threadPrint(%i)", x);
    return 0;
}

void thread(){
    NSThread *myThread = [[NSThread alloc] initWithTarget:myThread selector:threadPrint(20) object:nil];
    NSThread *myThread1 = [[NSThread alloc] initWithTarget:myThread1 selector:threadPrint(30) object:nil];
    NSThread *myThread2 = [[NSThread alloc] initWithTarget:myThread2 selector:threadPrint(40) object:nil];
    [myThread start];
    [myThread1 start];
    [myThread2 start];
}

void archive(){
    NSDictionary *glossary = [NSDictionary dictionaryWithObjectsAndKeys:@"app", @"A", @"game", @"G", @"Novel", @"N", nil];
    NSString *desktop = @"/Users/bigmonkey815/Desktop/";
    NSString *dictxml = [desktop stringByAppendingString:@"dict.xml"];
    
    [glossary writeToFile:dictxml atomically:YES];
    
    NSString *filestr = [NSString stringWithContentsOfFile:dictxml 
                                                  encoding:NSUTF8StringEncoding error:nil];
    NSLog(@"%@", filestr);
    
    NSDictionary *glossary_ = [NSDictionary dictionaryWithContentsOfFile:dictxml];
    NSLog(@"%@", glossary_);
    
    NSArray *array = [NSArray arrayWithObjects:@"Jan", @"Feb", @"Mar", @"Apr", @"May", nil];
    NSString *arrayxml = [desktop stringByAppendingString:@"array.xml"];
    
    [array writeToFile:arrayxml atomically:YES];
    
    filestr = [NSString stringWithContentsOfFile:arrayxml 
                                                  encoding:NSUTF8StringEncoding error:nil];
    NSLog(@"%@", filestr);
    
    NSArray *array_ = [NSArray arrayWithContentsOfFile:arrayxml];
    NSLog(@"%@", array_
          );
    
    NSString *dictarch = [desktop stringByAppendingString:@"dict.arch"];
    [NSKeyedArchiver archiveRootObject:glossary toFile:dictarch];
    NSDictionary *dict = [NSKeyedUnarchiver unarchiveObjectWithFile:dictarch];
    for(NSString *key in dict) 
        NSLog(@"%@ = %@", key, [dict objectForKey:key]);
    
    
    
}

void trycatch(){
    NSString *str = [[NSString alloc] init];
    @try {
        char c = [str characterAtIndex:0];
    }
    @catch (NSException *exception) {
        NSLog(@"exception");
    }
    @finally {
        ;
    }
    
}

void date(){
    NSDate *yesterday = [NSDate dateWithTimeIntervalSinceNow:-24*60*60];
    NSLog(@"%@", yesterday);
    NSDate *today = [NSDate dateWithTimeIntervalSinceNow:0];
    NSLog(@"%@", [today laterDate:yesterday]);
    
    NSDateFormatter *format = [[NSDateFormatter alloc] init];
    [format setDateFormat:@"yy/MM/dd"];
    NSDate *date = [format dateFromString:@"13/01/23"];
    NSLog(@"%@", date);
    
    NSDateComponents *com = [[NSDateComponents alloc] init];
    [com setDay:30];
    [com setMonth:1];
    [com setYear:2014];
    NSCalendar *cal = [NSCalendar currentCalendar];
    NSDate *comDate = [cal dateFromComponents:com];
    NSLog(@"%@", comDate);
    
    NSArray *timeZones = [NSTimeZone knownTimeZoneNames];
    NSDate *zoneDate = [NSDate date];
    for(NSString *zoneName in timeZones){
        NSTimeZone *zone = [[NSTimeZone alloc] initWithName:zoneName];
        NSDateFormatter *formatter = [[NSDateFormatter alloc] init];
        [formatter setDateFormat:@"yyyy/MM/dd HH:mm:ss"];
        [formatter setTimeZone:zone];
        NSString *dateStr = [formatter stringFromDate:date];
        NSLog(@"%@:%@", [zone name], dateStr);
    }
}

int main (int argc, const char * argv[])
{

    @autoreleasepool {
//        data_type();
//        test_obj();
//        foundation_obj();
//        file();
//        folder();
//        process();
//        thread();
//        archive();
        trycatch();
        date();
    }
    return 0;
}

