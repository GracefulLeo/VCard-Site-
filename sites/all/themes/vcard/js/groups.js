(function ($) {
  Drupal.behaviors.actionArrows = {
    attach: function (context) {
      $(context).on('click', '.contact-wrapper', function (event) {
        $(this).addClass('expanded').siblings().removeClass('expanded');

        var icon = $(event.currentTarget).find('.vcard-image').is(':visible') ? 'keyboard_arrow_down' : 'keyboard_arrow_up';
        $(this).find('i.material-icons').text(icon);
        $(this).find('.vcard-image').slideToggle();
      });
    }
  };

  Drupal.behaviors.groupActionsDropdown = {
    attach: function (context) {
      $('#group-options', context).bind('click', function () {
        $(this).toggleClass('active');
        $('.dropdown-group-menu').fadeToggle();
      });
    }
  };

  Drupal.behaviors.setActiveContactsInList = {
    attach: function (context) {
      $('#vcard-main-group-manage-contacts-form', context).find('input:checked').parent().addClass('active');
      $('#vcard-main-group-manage-contacts-form', context).find('label').bind('click', function () {
        $(this).parent().toggleClass('active');
      })
    }
  };
})(jQuery);