jQuery(document).ready(function ($) {
  setTimeout(function () {
    $('.hint-outer').fadeIn('slow')
  }, 1000);

  $('.hint-outer').on('click', function (event) {
    $(event.currentTarget).hide()
  })
});