<div class="group-view-loaded">
  <?php foreach ($contacts as $contact) : ?>
      <div class="contact-wrapper">
          <div class="contact-info">
              <div class="contact-logo logo-micro">
                <?php print render($contact['logo']); ?>
              </div>
              <div class="contact-person">
              <span class="full-name">
                  <?php print render($contact['full_name']); ?>
              </span>
                  <span class="position">
                  <?php print render($contact['position']); ?>
              </span>
              </div>
              <i class="material-icons">keyboard_arrow_down</i>
          </div>
          <div class="vcard-image">
              <img src="<?php print $contact['vcard']; ?>"/>
          </div>
      </div>
  <?php endforeach; ?>
</div>
