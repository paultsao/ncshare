$(function() {
	$('head').append('<style>#share-box{background:white;width:110px;z-index:1000;position:absolute;border:1px solid #e8e8e8;margin-top:-2px}#share-box ul{list-style-type:none;padding:0;margin:0;}#share-box ul li a{text-decoration:none;height:20px;display:block}#share-box ul li a:hover{background-color:#336699;color:#fff;text-decoration:none}#share-box img{vertical-align:middle;width:16px;height:16px;border:0;margin-right:5px}</style>');

	var shareConfig = {
	    "Facebook": {
	        "url": "http://www.facebook.com/sharer/sharer.php?u=%SHARE_URL%",
	        "icon": "facebook-16.png"
	    },
	    "Twitter": {
	        "url": "http://twitter.com/intent/tweet?via=interior&amp;url=%SHARE_URL%&amp;text=%SHARE_TITLE%",
	        "icon": "twitter-16.png"
	    },
	    "Google+": {
	        "url": "https://plus.google.com/share?url=%SHARE_URL%",
	        "icon": "google-plus-16.png"
	    },
	    "LinkedIn":{
		url:"http://www.linkedin.com/shareArticle?mini=true&url=%SHARE_URL%&title=%SHARE_TITLE%",
		icon:"linkedin-16.png"
	    },
	    "Delicious":{
		url:"https://delicious.com/save?v=5&noui&jump=close&url=%SHARE_URL%&title=%SHARE_TITLE%",
		icon:"delicious-16.png"
	    },
	    "Digg":{
		url:"http://digg.com/submit?url=%SHARE_URL%&title=%SHARE_TITLE%",
		icon:"digg-16.png"
	    },
	    "Reddit":{
		url:"http://reddit.com/submit?url=%SHARE_URL%&title=%SHARE_TITLE%",
		icon:"reddit-16.png"
	    },
	    "StumbleUpon":{
		url:"http://www.stumbleupon.com/submit?url=%SHARE_URL%&title=%SHARE_TITLE%",
		icon:"stumbleupon-16.png"
	    }
	};
	var currentPage = window.location.href;
	var title = document.title;
	if(typeof imagePath === 'undefined'){imagePath="/images/"};
	var shareHTML = '<div id="share-box"><ul>';

	$.each(shareConfig, function(name, site) {
		shareHTML = shareHTML + '<li><a href="' + site.url.replace("%SHARE_URL%", encodeURIComponent(currentPage)).replace("%SHARE_TITLE%", encodeURIComponent(title)) + '" target="_blank"><img src="' + imagePath + site.icon + '" alt="Share on ' + name + '" />' + name + '</a></li>';
	});
	shareHTML = shareHTML + '</ul></div>';

	$('#ncshare').hover(function() {
		$(this).append(shareHTML);
	}, function() {
		$(this).find("div:last").remove();
	});

});