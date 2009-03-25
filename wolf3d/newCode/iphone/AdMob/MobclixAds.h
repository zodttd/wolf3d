//AdViewDelegate
@protocol MobclixAdViewDelegate;

//Abstract Ad View - Should not be instantiated directly.
@interface MobclixAdView : UIWebView <UIWebViewDelegate> {
	id delegate;
	NSString *adCode;
	
@private
	NSURLResponse* _response;
	NSMutableData* _data;
	NSURLConnection* _connection;
}

@property(nonatomic, assign) id<MobclixAdViewDelegate> delegate;
@property(nonatomic, retain) NSString *adCode;

- (void) getAd;
- (void) cancelAd;

@end

//MMA X-Large Banner 300x50
@interface MMABannerXLAdView : MobclixAdView {}
@end

//IAB Medium Rectangle 300x250
@interface IABRectangleMAdView : MobclixAdView {}
@end

//IAB Square 250x250
@interface IABSquareAdView : MobclixAdView {}
@end

//iPhone Full Screen 320x480
@interface FullScreenAdView : MobclixAdView {}
@end


@protocol MobclixAdViewDelegate <NSObject>

@optional
- (void) adViewDidFinishLoad:(MobclixAdView *) adView;
- (void) adViewDidFailLoad: (MobclixAdView *) adView;
- (BOOL) adViewShouldTouchThrough: (MobclixAdView *) adView;
- (void) adViewDidFinishTouchThrough: (MobclixAdView *) adView;

@end