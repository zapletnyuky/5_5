#include "Header.h"
#import <XCTest/XCTest.h>

@interface teest : XCTestCase

@end

@implementation teest

- (void)testLab {
    srand((unsigned)time(NULL));
    cout << "binarty = " << to_binary_string(5) << endl;
    
    XCTAssertEqual(to_binary_string(5), to_binary_string(5));
    
}

@end
