jQuery(document).ready(function ($) {

  var canvas = new fabric.Canvas('vcard-constructor');
  canvas.backgroundColor = '#fbfff8';

  var $form = $('#vcard-main-my-vcard-form');
  var fieldsText = $form.find('.field-type-text, .field-type-email');

  // Add image on canvas if loaded before.
  addLogo();
  // Add behavior for ajax image load preview.
  Drupal.behaviors.addImg = {
    attach: function () {
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
    }
  };
  // @todo Need to add behavior for multiple fields (input.length > 1).

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

  /**
   * Save canvas to field.
   */
  $('#my-vcard-form-submit').on('click', function () {
    $('#edit-field-base64-vcard-und-0-value').val(canvas.toDataURL('png'));
  });

  // Hide field_base64_vcard if its view textfield, but not image.
  $('.field-name-field-base64-vcard').find('textarea')
      .closest('.field-name-field-base64-vcard').css({display: 'none'});

});