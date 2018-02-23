(function ($) {
  Drupal.behaviors.entityViewAjaxLoad = {
    attach: function (context) {
      $('.list-item:not(.list-item-processed)', context)
          .bind('click', function () {
            var itemType = $(this).data('type');
            $(this).siblings().removeClass('list-item-processed');
            $(this).addClass('list-item-processed');
            $('.entity-view-wrapper')
                .find('.nano-content')
                .load(Drupal.settings.basePath + 'ajax/' + itemType + '/' + parseInt($(this).data('id'), 10) + '/view');
            return false;
          });
    }
  };
})(jQuery);