<button type="submit" <?php optimize_mikado_inline_style($button_styles); ?> <?php optimize_mikado_class_attribute($button_classes); ?> <?php echo optimize_mikado_get_inline_attrs($button_data); ?> <?php echo optimize_mikado_get_inline_attrs($button_custom_attrs); ?>>
    <span class="mkdf-btn-text"><?php echo esc_html($text); ?></span>

	<?php if($show_icon) : ?>
		<span class="mkdf-btn-icon-holder">
			<?php echo optimize_mikado_icon_collections()->renderIcon($icon, $icon_pack, array(
				'icon_attributes' => array(
					'class' => 'mkdf-btn-icon-elem'
				)
			)); ?>
		</span>
	<?php endif; ?>

	<?php if($display_helper) : ?>
		<span class="mkdf-btn-helper" <?php optimize_mikado_inline_style($helper_styles); ?>></span>
	<?php endif; ?>

</button>