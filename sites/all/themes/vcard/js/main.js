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
  }
})(jQuery);