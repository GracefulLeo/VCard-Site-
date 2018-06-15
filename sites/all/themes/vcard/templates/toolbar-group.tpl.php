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
            <span class="group-title"><?php print $title; ?></span>
            <span class="group-description"><?php print $description; ?></span>
        </div>
        <div class="group-actions">
            <i class="material-icons">
              <?php print l('person_add', 'group/manage-contacts/' . $entity_id . '/nojs', [
                'attributes' => [
                  'class' => [
                    'ctools-use-modal',
                    'ctools-modal-groups-popup',
                  ],
                ],
              ]); ?>
            </i>
            <i class="material-icons">
              <?php print l('edit', 'group/edit/' . $entity_id . '/nojs', [
                'attributes' => [
                  'class' => [
                    'ctools-use-modal',
                    'ctools-modal-groups-popup',
                  ],
                ],
              ]); ?>
            </i>
            <i class="material-icons">
              <?php print l('delete', 'group/delete/' . $entity_id . '/nojs', [
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
