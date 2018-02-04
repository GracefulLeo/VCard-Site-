(function ($) {
  Drupal.behaviors.vcardMain = {
    'attach': function (context) {
      $('.list-item:not(.vcard-processed)', context)
          .bind('click', function () {
            $(this).siblings().removeClass('vcard-processed');
            $(this).addClass('vcard-processed');
            $('#vcard-view-wrapper').find('.nano-content').load('/vcard/my-vCards-deliver/' + parseInt($(this).data('id'), 10) + '/edit');
            return false;
          });
    }
  };
})(jQuery);