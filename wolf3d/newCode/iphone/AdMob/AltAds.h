//
//  untitled.h
//  SBSettings
//
//  Created by mark on 10/30/08.
//  Copyright 2008 __MyCompanyName__. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "AdMobDelegateProtocol.h"
#import "AdMobView.h"
#import "Mobclix.h"
#import "MobclixAds.h"

#define AD_REFRESH_PERIOD 60.0 // display fresh ads once per minute

#define ADS_ADMOB		0
#define ADS_MOBCLIX		1
#define ADS_MINE		2
#define ADS_TOTAL		3


@interface AltAds : UIView <UIWebViewDelegate, MobclixAdViewDelegate, AdMobDelegate> 
{
	NSTimer*			AdTimer;
	UIWebView*			AdView;
	int					AdSet;
	MMABannerXLAdView*	adMcView;
	AdMobView*			adMobAd;
	NSTimer*			autoslider; // timer to slide in fresh ads
	int					AdsArray[ADS_TOTAL];
	int					CurrentAd;
	BOOL				adTimerShouldStop;
	BOOL				loadAdInFrame;
}
- (id)   initWithFrame:(CGRect)frame andWindow:(UIWindow*)_window;
- (void) AdTimerExpired:(NSTimer *)timer;
- (void) webViewDidFinishLoad:(UIWebView*) webView;
- (void) webView:(UIWebView *)webView didFailLoadWithError:(NSError *)error;
- (void) RefreshAd;
- (void) connection:(NSURLConnection *)connection didReceiveData:(NSData *)data;
- (void) startAdmob;
- (void) startMobclix;
- (void) refreshAdmob:(NSTimer *)timer; 
- (void) IncrementCurrentAdAndTryNext;
- (void) stopAdTimers;

- (void) MobclixEndApplication;
+ (BOOL) isAdBlockingEnabled;

@end
