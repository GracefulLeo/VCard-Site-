(function ($) {
  Drupal.behaviors.exposedAutoSubmitFix = {
    attach: function (context) {
      // This magic fixed autosubmit ctools exposed filter on blur.
      $('.ctools-auto-submit-processed', context)
          .bind('blur', function () {
            $('#edit-submit-contacts').removeClass('ctools-auto-submit-click');
          })
          .bind('focus', function () {
            $('#edit-submit-contacts').addClass('ctools-auto-submit-click');
          });
    }
  }
})(jQuery);