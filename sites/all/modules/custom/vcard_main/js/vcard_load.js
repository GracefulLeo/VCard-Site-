(function ($) {
  Drupal.behaviors.vcardMain = {
    'attach': function (context) {
      $('.list-item:not(.vcard-processed)', context)
          .bind('click', function () {
            $(this).siblings().removeClass('vcard-processed');
            $(this).addClass('vcard-processed');
            $('.vcard-view-wrapper')
                .find('.nano-content')
                .load(Drupal.settings.basePath + 'ajax/vcard/' + parseInt($(this).data('id'), 10) + '/view');
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