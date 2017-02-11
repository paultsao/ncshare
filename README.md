# NCShare

##### No Cookies Share is a jQuery plugin that allows you to easily share your page without any invasive tracking cookies

## Setup

```html
<a id="ncshare">
	<img src="/images/share-32.png" width="32" height="32" border="0"/>
</a>
<script>var imagePath = "/images/";</script>
<script type="text/javascript" src="/js/ncshare.min.js"></script>
```

Set default image path where you store icon files. If `imagePath` is undefined, default value is `"/images/"`.

```javascript
var imagePath = "/images/";
```

## Drupal 7 Module

Integrated with node types to use with social widget.

Works best with [Pathauto module](https://www.drupal.org/project/pathauto) for URL/path alias.

### Installation

1. Upload content of the `drupal-7.x` folder to `/sites/all/modules/ncshare/` directory.
2. Enable the NCShare module through either 'Modules' menu in Drupal or drush.
3. Go to `/admin/config/services/ncshare` to configure social widget with label and URLs. In addition, select node types to use with the social widget.

### Sharing URLs

Facebook: http://www.facebook.com/sharer/sharer.php?u=[node:url:absolute]
Twitter: http://twitter.com/intent/tweet?url=[node:url:absolute]&text=[node:title]
Google+: https://plus.google.com/share?url=[node:url:absolute]
LinkedIn: http://www.linkedin.com/shareArticle?mini=true&url=[node:url:absolute]&title=[node:title]
Delicious: https://delicious.com/save?v=5&noui&jump=close&url=[node:url:absolute]&title=[node:title]
Digg: http://digg.com/submit?&url=[node:url:absolute]&title=[node:title]
Reddit: http://reddit.com/submit?&url=[node:url:absolute]&title=[node:title]
StumbleUpon: http://www.stumbleupon.com/submit?url=[node:url:absolute]&title=[node:title]
Pinterest: http://pinterest.com/pin/create/button/?url=[node:url:absolute]&title=[node:title]

## License

[MIT licensed][1]

[1]:http://opensource.org/licenses/MIT
