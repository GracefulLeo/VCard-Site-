(function ($) {
  Drupal.behaviors.actionArrows = {
    attach: function (context) {
      $('.contact-wrapper', context).bind('click', function (event) {
        $(this).addClass('expanded').siblings().removeClass('expanded');

        var icon = $(event.currentTarget).find('.vcard-image').is(':visible') ? 'keyboard_arrow_down' : 'keyboard_arrow_up';
        $(this).find('i.material-icons').text(icon);
        $(this).find('.vcard-image').slideToggle();
      });
    }
  };
})(jQuery);