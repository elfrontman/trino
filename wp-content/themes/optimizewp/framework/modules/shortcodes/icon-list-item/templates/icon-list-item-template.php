<div <?php optimize_mikado_inline_style($holder_styles); ?> <?php optimize_mikado_class_attribute($holder_classes); ?>>
	<div class="mkdf-icon-list-icon-holder">
        <div class="mkdf-icon-list-icon-holder-inner clearfix">
			<?php echo optimize_mikado_icon_collections()->renderIcon($icon, $icon_pack, $params);
			?>
		</div>
	</div>
	<p class="mkdf-icon-list-text" <?php echo optimize_mikado_get_inline_style($title_style)?> > <?php echo esc_attr($title)?></p>
</div>