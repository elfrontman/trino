<div <?php optimize_mikado_class_attribute($holder_classes); ?> <?php echo optimize_mikado_get_inline_attrs($holder_data); ?>>
    <div class="mkdf-iwt-content-holder">
        <div class="mkdf-iwt-icon-title-holder">
            <div class="mkdf-iwt-icon-holder">
	            <span class="mkdf-iwt-icon-holder-inner">
				    <?php if(!empty($custom_icon)) : ?>
					    <?php echo wp_get_attachment_image($custom_icon, 'full'); ?>
				    <?php else: ?>
					    <?php echo optimize_mikado_get_shortcode_module_template_part('templates/icon', 'icon-with-text', '', array('icon_parameters' => $icon_parameters)); ?>
				    <?php endif; ?>
	            </span>
            </div>
            <div class="mkdf-iwt-title-holder">
                <<?php echo esc_attr($title_tag); ?> <?php optimize_mikado_inline_style($title_styles); ?>><?php echo esc_html($title); ?></<?php echo esc_attr($title_tag); ?>>
            </div>
        </div>
        <div class="mkdf-iwt-text-holder">
            <p <?php optimize_mikado_inline_style($text_styles); ?>><?php echo esc_html($text); ?></p>

            <?php if(!empty($link) && !empty($link_text)) : ?>
                <a class="mkdf-iwt-link" href="<?php echo esc_attr($link); ?>" <?php optimize_mikado_inline_attr($target, 'target'); ?>><?php echo esc_html($link_text); ?></a>
            <?php endif; ?>
        </div>
    </div>
</div>