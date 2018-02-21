(function ($) {
  Drupal.behaviors.vcardMain = {
    'attach': function (context) {
      var itemType = 'vcard';

      $('.list-item-' + itemType + ':not(.list-item-processed)', context)
          .bind('click', function () {
            $(this).siblings().removeClass('list-item-processed');
            $(this).addClass('list-item-processed');
            $('.entity-view-wrapper')
                .find('.nano-content')
                .load(Drupal.settings.basePath + 'ajax/' + itemType + '/' + parseInt($(this).data('id'), 10) + '/view');
            return false;
          });

      // This magic fixed autosubmit ctools exposed filter on blur.
      $('.ctools-auto-submit-processed')
          .on('blur', function () {
            $('#edit-submit-contacts').removeClass('ctools-auto-submit-click');
          })
          .on('focus', function () {
            $('#edit-submit-contacts').addClass('ctools-auto-submit-click');
          });
    }
  };
})(jQuery);