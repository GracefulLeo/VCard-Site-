(function ($) {
  Drupal.behaviors.entityListDisplay = {
    attach: function (context) {
      $('.list-item:not(.list-item-processed)', context).bind('click', function () {
        $('.list-wrapper').find('.list-item-processed').removeClass('list-item-processed');
        $(this).addClass('list-item-processed');
      });
    }
  };

  Drupal.behaviors.entityViewAjaxLoad = {
    attach: function (context) {
      $('.view-contacts .list-item:not(.list-item-processed)', context)
          .bind('click', function () {
            var id = parseInt($(this).data('id'), 10);
            $('.entity-view-wrapper')
                .find('.nano-content')
                .load(Drupal.settings.basePath + 'ajax/vcard/' + id + '/view');

            return false;
          });
    }
  };
})(jQuery);