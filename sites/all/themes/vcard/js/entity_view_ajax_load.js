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

              // Set currentTarget id to "edit" and "remove" links.
              $('#group-edit').bind('click', function () {
                var url = Drupal.settings.basePath + 'group/edit/' + id + '/nojs';
                var link = $('<a></a>').attr('href', url)
                    .addClass('ctools-modal-groups-popup ctools-use-modal-processed')
                    .click(Drupal.CTools.clickAjaxLink);
                Drupal.ajax[url] = new Drupal.ajax(url, link.get(0), {
                  url: url,
                  event: 'click'
                });
                link.click();
              });
              $('#group-delete').bind('click', function () {
                var url = Drupal.settings.basePath + 'group/delete/' + id + '/nojs';
                var link = $('<a></a>').attr('href', url)
                    .addClass('ctools-modal-groups-popup ctools-use-modal-processed')
                    .click(Drupal.CTools.clickAjaxLink);
                Drupal.ajax[url] = new Drupal.ajax(url, link.get(0), {
                  url: url,
                  event: 'click'
                });
                link.click();
              });
            }

            return false;
          });
    }
  };
})(jQuery);