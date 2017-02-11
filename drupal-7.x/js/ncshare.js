(function($) {
  Drupal.behaviors.ncshare = {
    attach: function(context, settings) {
      $('.share-trigger', context).click(function(e) {
        e.preventDefault();
      }).on('focus', function(e) {
        $(this).next('.share-links').toggleClass('active');
      }).on('blur', function(e) {
        setTimeout(function() {
          $(this).next('.share-links').toggleClass('active');
        }.bind(this), 2500);
      })
    }
  };
})(jQuery);
