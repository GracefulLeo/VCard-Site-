<div class="vcard-view-loaded">
    <div class="vcard-image">
        <img src="<?php print $base64; ?>">
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
