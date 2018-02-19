(function ($) {
      Drupal.behaviors.autoUpload = {
        attach: function (context) {
          var $field = $('.field-name-field-logotype');

          var $input = $(document.createElement('input')).attr({
            type: 'text',
            id: 'pseudo-field-logotype',
            placeholder: $field.find('label').html()
          });

          if (!$field.find('.image-preview').length && !$field.find('#pseudo-field-logotype').length) {
            // Add custom text field and hide "Upload" button.
            $field.find('.image-widget-data').prepend($input).find('.form-submit').addClass('element-invisible');
            // Click on "file" field on custom text field click.
            $('#pseudo-field-logotype', context).on('click', function () {
              $(this).siblings('.form-file').click();
            });
          }
          else {
            // Print help text near regular button.
            var $span = $(document.createElement('span')).text(Drupal.t('Logotype uploaded')).addClass('logo-text');
            $field.find('.file').html($span);
          }

          // Auto upload image from custom text field.
          $('.field-name-field-logotype input.form-file', context).once(function () {
            $(this).change(function () {
              $(this).siblings('.form-submit').mousedown();
            });
          })
        }
      }
    }
)(jQuery);