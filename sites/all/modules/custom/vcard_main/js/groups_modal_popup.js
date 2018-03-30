(function ($) {
  Drupal.theme.prototype.groupsPopupHTML = function () {
    return '<div id="ctools-modal" class="popups-box groups-popup">' +
        '     <div class="ctools-modal-content ctools-modal-groups-popup">' +
        '       <div class="modal-header">' +
        '         <span id="modal-title" class="modal-title"></span>' +
        '       </div>' +
        '       <div class="modal-msg"></div>' +
        '       <div class="modal-scroll content-wrapper">' +
        '         <div class="nano">' +
        '           <div id="modal-content" class="modal-content group-body nano-content"></div>' +
        '         </div>' +
        '       </div>' +
        '     </div>' +
        '   </div>';
  };

  Drupal.behaviors.addModalCloseIcon = {
    attach: function () {
      $('#modalBackdrop').html('<i class="material-icons popup-close">close</i>');
    }
  };

  Drupal.behaviors.alignPopup = {
    attach: function () {
      if ($('#modalContent').length) {
        setTimeout(function () {
          modalContentResize();
          $('#modalBackdrop').css({height: '100%', width: '100%'});
        }, 100)
      }
    }
  };

  Drupal.behaviors.closePopups = {
    attach: function () {
      $('#modalBackdrop').bind('click', function () {
        modalContentClose()
      })
    }
  };
})(jQuery);