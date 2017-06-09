//
//  ViewController.m
//  Demo
//
//  Created by colin on 17/6/9.
//  Copyright © 2017年 Colin. All rights reserved.
//

#import "ViewController.h"
#import "NSString+CHChinese.h"

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
    NSString *test = @"中";
    
    NSString *test2 = @"中文和标点：，";
    
    NSString *test3 = @"混合文本，composite!😄";
    
    BOOL isChinese = [test ch_isChinese:CHNSStringChineseTypeAll];
    NSLog(@"%@ is Chinese:%d", test, isChinese);
    
    BOOL isContained = [test2 ch_containsChinese:CHNSStringChineseTypePunctuation];
    NSLog(@"%@ contains Chinese:%d", test2, isContained);
    
    NSString *substring = [test3 ch_substringWithChinese:CHNSStringChineseTypeCharacter inRange:NSMakeRange(0, test3.length)];
    NSLog(@"Substring--Before:%@\n After:%@", test3, substring);
    
    [test3 ch_enumerateChinese:CHNSStringChineseTypeAll
                       inRange:NSMakeRange(0, test3.length)
                    usingBlock:^(NSString * _Nullable substring, NSRange substringRange, NSRange enclosingRange, BOOL * _Nonnull stop) {
                        NSLog(@"Chinese:%@", substring);
                    }];
    
    NSString *replaced = [test3 ch_stringByReplacingChinese:CHNSStringChineseTypeCharacter withString:@"A"];
    NSLog(@"Replaced--Before:%@\n After:%@", test3, replaced);
    
    NSString *trimmed = [test3 ch_stringByTrimmingChinese:CHNSStringChineseTypeAll];
    NSLog(@"Trimmed--Before:%@\n After:%@", test3, trimmed);
}


- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}


@end
