(function ($) {
  Drupal.behaviors.entityViewAjaxLoad = {
    attach: function (context) {
      $('.list-item:not(.list-item-processed)', context)
          .bind('click', function () {
            var id = parseInt($(this).data('id'), 10);
            var itemType = $(this).data('type');
            $(this).siblings().removeClass('list-item-processed');
            $(this).addClass('list-item-processed');
            $('.entity-view-wrapper')
                .find('.nano-content')
                .load(Drupal.settings.basePath + 'ajax/' + itemType + '/' + id + '/view');

            if (itemType === 'group') {
              $('.group-toolbar-column').css('display', 'flex');
              // Get group title and description.
              $.get(Drupal.settings.basePath + 'ajax/' + itemType + '/' + id + '/credits', null, function (response) {
                $('.group-header-wrapper .group-title').text(response.title);
                $('.group-header-wrapper .group-description').text(response.description || '');
              });
            }
            return false;
          });
    }
  };
})(jQuery);