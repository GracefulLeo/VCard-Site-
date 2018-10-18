<div class="large-4 medium-4 columns">
    <div class="my-vcards-toolbar-column left">
        <div class="my-vcards-actions">
            <a href="my-vcards/add"><i class="material-icons">add</i></a>
        </div>
    </div>
</div>
<div class="large-8 medium-8 columns">
    <div class="my-vcards-toolbar-column right">
        <div class="my-vcards-actions">
            <a href="<?php print "my-vcards/{$entity_id}/edit"; ?>">
                <i class="material-icons">edit</i>
            </a>
            <a href="<?php print "my-vcards/{$entity_id}/clone"; ?>">
                <i class="material-icons">content_copy</i>
            </a>
            <a href="<?php print "my-vcards/{$entity_id}/remove"; ?>">
                <i class="material-icons">delete</i>
            </a>
        </div>
    </div>
</div>
