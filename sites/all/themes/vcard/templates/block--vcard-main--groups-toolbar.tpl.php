<div class="large-4 medium-4 columns">
    <div class="group-toolbar-column">
        <div class="group-actions">
            <i class="material-icons">
              <?php print l('group_add', 'group/add/nojs', [
                'attributes' => [
                  'class' => [
                    'ctools-use-modal',
                    'ctools-modal-groups-popup',
                  ],
                ],
              ]); ?>
            </i>
        </div>
    </div>
</div>
<div class="large-8 medium-8 columns">
    <div class="group-toolbar-column">
        <div class="group-header-wrapper">
            <span class="group-title"></span>
            <span class="group-description"></span>
        </div>
        <div class="group-actions">
            <i class="material-icons" id="group-contact-edit">person_add</i>
            <i class="material-icons" id="group-options">more_vert</i>
        </div>
        <nav class="dropdown-group-menu">
            <ul class="links inline-list clearfix">
                <li>
                    <span id="group-edit">
                      <?php print t('Edit group'); ?>
                    </span>
                </li>
                <li>
                  <span id="group-delete">
                      <?php print t('Delete group'); ?>
                    </span>
                </li>
            </ul>
        </nav>
    </div>
</div>
