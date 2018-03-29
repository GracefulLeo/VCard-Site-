(function ($) {
  var canvas = null;

  Drupal.behaviors.constructorVCard = {
    attach: function () {
      if (canvas === null) {
        canvas = new fabric.Canvas('vcard-constructor');
      }
      else {
        canvas.clear();
      }

      canvas.backgroundColor = '#fbfff8';

      var $form = $('#vcard-main-my-vcard-form');
      var fieldsText = $form.find('.form-type-textfield');
      // Add image on canvas if loaded before.
      addLogo();

      // Add behavior for ajax image load preview.
      var fieldImg = $form.find('.image-preview img');
      if (fieldImg[0]) {
        addLogo()
      }
      else {
        var objs = canvas.getObjects();
        objs.forEach(function (t) {
          if (t.type === 'image') {
            canvas.remove(t);
          }
        })
      }

      // Array with ids of DOM elements.
      var fields = [];
      fieldsText.each(function () {
        var input = $(this).find('input');

        if (input.length > 1) {
          for (const i in input) {
            if (input.hasOwnProperty(i) && $(input[i]).attr('type') === 'text') {
              fields.push($(input[i]).attr('id'))
            }
          }
        }
        else {
          fields.push(input.attr('id'));
        }

      });

      // @todo Test variable.
      var elPadding = 10;

      // Object contains fabric.Objects.
      var elements = {};

      // Define fabric.Objects and save to variable.
      fields.forEach(function (item) {
        // Do not need render VCard title on canvas.
        if (item === 'edit-title') {
          return;
        }

        elements[item] = new fabric.Text($('#' + item).val(), {
          fontSize: 16,
          top: elPadding,
          left: 260,
          hasControls: false,
          lockMovementX: true,
          lockMovementY: true
        });
        elPadding += 16;
      });

      // Add all objects to canvas.
      for (var el in elements) {
        canvas.add(elements[el])
      }

      // Render text from fields on canvas.
      for (const el in elements) {
        $('#' + el).on('keyup', function () {
          elements[el].setText($(this).val());
          canvas.renderAll()
        })
      }

      /**
       * Render image preview on canvas.
       */
      function addLogo() {
        var fieldImg = $form.find('.image-preview img');
        fabric.Image.fromURL($(fieldImg).attr('src'), function (img) {
          img.set({
            top: 10,
            left: 10,
            selectable: false
          });
          canvas.add(img)
        });
      }

      /**
       * Listeners.
       */
      canvas.on({
        'object:selected': objectSelected,
      });

      /**
       * Callback function for object:selected event.
       */
      function objectSelected() {
        var obj = canvas.getActiveObject();
        var group = canvas.getActiveGroup();

        if (obj && obj.type === 'text') {
          // Make active input if field on canvas selected.
          for (const el in elements) {
            if (elements[el] === obj) {
              // Bug in Chrome fixed with setTimeout solution.
              setTimeout(function () {
                $('#' + el).select().focus()
              }, 1)
            }
          }
        }

        if (group) {
          group.set({
            hasControls: false,
            lockMovementX: true,
            lockMovementY: true
          })
        }
      }
    }
  };

  Drupal.behaviors.saveVCard = {
    attach: function (context) {
      $('#my-vcard-form-submit', context).once().bind('click', function () {
        $('#base64-vcard').val(canvas.toDataURL('png'));
      });
    }
  };

  // @todo Add validators for all fields.
  Drupal.behaviors.vcardFormValidation = {
    attach: function (context) {
      $('#vcard-main-my-vcard-form', context).validate({
        rules: {
          'surname': {
            required: true
          },
          'name': {
            required: true
          },
          'email': {
            email: true
          }
        }
      })
    }
  };
})(jQuery);