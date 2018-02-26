(function ($) {
  Drupal.behaviors.themeVCard = {
    attach: function (context) {
      // Initialize NanoScroller.
      $(".nano", context).nanoScroller();

      $('.dropdown-header', context).hover(function () {
        $(this).find('.icon-bar:nth-child(2)').addClass('active');
      }, function () {
        $(this).find('.icon-bar:nth-child(2)').removeClass('active');
      }).on('click', function () {
        $('.dropdown-menu').fadeToggle();
        $(this).toggleClass('active');
      }).on('mouseleave', function () {
        $('.dropdown-menu').fadeOut();
        $(this).removeClass('active');
      })
    }
  };

  Drupal.behaviors.event = {
    attach: function (context) {
      $(context).ajaxStart(function () {
        $('.ajax-vcard-throbber-wrapper', context).css({
          'z-index': 9999,
          'opacity': '.2'
        })
      });
      $(context).ajaxSuccess(function () {
        // Set delay for very fast ajax, because fast flashing is bad for eyes.
        setTimeout(function () {
          $('.ajax-vcard-throbber-wrapper', context).css({
            'z-index': -9999,
            'opacity': 0
          })
        }, 300)
      })
    }
  }
})(jQuery);