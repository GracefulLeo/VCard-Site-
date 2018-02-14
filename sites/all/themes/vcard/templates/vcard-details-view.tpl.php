<div class="vcard-view-wrapper">
    <div class="vcard-with-actions">
        <div class="vcard-image">
            <?php print drupal_render($img); ?>
        </div>
      <?php if ($editable): ?>
          <div class="actions">
              <a href="my-vcards/<?php print $id; ?>/edit">
                  <i class="material-icons">border_color</i>
              </a>
              <a href="my-vcards/<?php print $id; ?>/clone">
                  <i class="material-icons">content_copy</i>
              </a>
              <a href="my-vcards/<?php print $id; ?>/remove">
                  <i class="material-icons">delete</i>
              </a>
          </div>
      <?php endif; ?>
    </div>
    <div class="vcard-description">
        <div class="row">
            <div class="large-6 columns full-name">
                <div class="icon">
                    <i class="material-icons">account_circle</i>
                </div>
                <div class="content">
                    <span><?php print $full_name; ?></span>
                </div>
            </div>
            <div class="large-6 columns company">
                <div class="icon">
                    <i class="material-icons">domain</i>
                </div>
                <div class="content">
                    <div><?php print $company; ?></div>
                    <div><?php print $position; ?></div>
                </div>
            </div>
        </div>
        <div class="row">
            <div class="large-6 columns communication">
                <div class="icon">
                    <i class="material-icons">contact_phone</i>
                </div>
                <div class="content">
                    <div><?php print $phones; ?></div>
                    <div><?php print $emails; ?></div>
                    <div><?php print $site; ?></div>
                </div>
            </div>
            <div class="large-6 columns address">
                <div class="icon">
                    <i class="material-icons">location_on</i>
                </div>
                <div class="content">
                    <div><?php print $address; ?></div>
                </div>
            </div>
        </div>
    </div>
</div>
