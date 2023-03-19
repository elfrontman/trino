<?php if(has_category()) : ?>
	<div class="mkdf-post-info-category mkdf-post-info-item">
		<?php esc_html_e('', 'optimize'); ?><span aria-hidden="true" class="icon_tags"></span><?php the_category(', '); ?>
	</div>
<?php endif; ?>