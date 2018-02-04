jQuery(document).ready(function ($) {
  // Initialize NanoScroller.
  $(".nano").nanoScroller();

  $('.dropdown-header').hover(function () {
    $(this).find('.icon-bar:nth-child(2)').addClass('active');
  }, function () {
    $(this).find('.icon-bar:nth-child(2)').removeClass('active');
  }).on('click', function () {
    $('.dropdown-menu').toggle();
    $(this).toggleClass('active');
  })
});