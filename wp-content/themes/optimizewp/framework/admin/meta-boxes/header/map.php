<?php

$header_meta_box = optimize_mikado_add_meta_box(
	array(
		'scope' => array('page', 'portfolio-item', 'post'),
		'title' => 'Header',
		'name'  => 'header_meta'
	)
);
optimize_mikado_add_meta_box_field(
	array(
		'name'          => 'mkdf_header_style_meta',
		'type'          => 'select',
		'default_value' => '',
		'label'         => 'Header Skin',
		'description'   => 'Choose a header style to make header elements (logo, main menu, side menu button) in that predefined style',
		'parent'        => $header_meta_box,
		'options'       => array(
			''             => '',
			'light-header' => 'Light',
			'dark-header'  => 'Dark'
		)
	)
);

optimize_mikado_add_meta_box_field(
	array(
		'parent'        => $header_meta_box,
		'type'          => 'select',
		'name'          => 'mkdf_enable_header_style_on_scroll_meta',
		'default_value' => '',
		'label'         => 'Enable Header Style on Scroll',
		'description'   => 'Enabling this option, header will change style depending on row settings for dark/light style',
		'options'       => array(
			''    => '',
			'no'  => 'No',
			'yes' => 'Yes'
		)
	)
);

switch(optimize_mikado_options()->getOptionValue('header_type')) {
	case 'header-standard':

		optimize_mikado_add_meta_box_field(
			array(
				'name'        => 'mkdf_menu_area_background_color_header_standard_meta',
				'type'        => 'color',
				'label'       => 'Background Color',
				'description' => 'Choose a background color for header area',
				'parent'      => $header_meta_box
			)
		);

		optimize_mikado_add_meta_box_field(
			array(
				'name'        => 'mkdf_menu_area_background_transparency_header_standard_meta',
				'type'        => 'text',
				'label'       => 'Transparency',
				'description' => 'Choose a transparency for the header background color (0 = fully transparent, 1 = opaque)',
				'parent'      => $header_meta_box,
				'args'        => array(
					'col_width' => 2
				)
			)
		);

		optimize_mikado_add_meta_box_field(array(
			'name'          => 'mkdf_menu_area_bottom_border_disable_header_standard_meta',
			'type'          => 'yesno',
			'label'         => 'Disable Header Bottom Border',
			'description'   => 'Disable this option will enable bottom border on header',
			'parent'        => $header_meta_box,
			'default_value' => 'no',
			'args'          => array(
				'dependence'             => true,
				'dependence_hide_on_yes' => '#mkdf_border_bottom_color_container',
				'dependence_show_on_yes' => '',
			)
		));

		$border_bottom_color_container = optimize_mikado_add_admin_container(array(
			'type'            => 'container',
			'name'            => 'border_bottom_color_container',
			'parent'          => $header_meta_box,
			'hidden_property' => 'mkdf_menu_area_bottom_border_enable_header_standard_meta',
			'hidden_value'    => 'yes'
		));

		optimize_mikado_add_meta_box_field(array(
			'name'        => 'mkdf_menu_area_bottom_border_color_meta',
			'type'        => 'color',
			'label'       => 'Header Bottom Border Color',
			'description' => 'Choose color of header bottom border',
			'parent'      => $border_bottom_color_container
		));

		break;

	case 'header-vertical':

		optimize_mikado_add_meta_box_field(array(
			'name'        => 'mkdf_vertical_header_background_color_meta',
			'type'        => 'color',
			'label'       => 'Background Color',
			'description' => 'Set background color for vertical menu',
			'parent'      => $header_meta_box
		));

		optimize_mikado_add_meta_box_field(array(
			'name'        => 'mkdf_vertical_header_transparency_meta',
			'type'        => 'text',
			'label'       => 'Transparency',
			'description' => 'Enter transparency for vertical menu (value from 0 to 1)',
			'parent'      => $header_meta_box,
			'args'        => array(
				'col_width' => 1
			)
		));

		optimize_mikado_add_meta_box_field(
			array(
				'name'          => 'mkdf_vertical_header_background_image_meta',
				'type'          => 'image',
				'default_value' => '',
				'label'         => 'Background Image',
				'description'   => 'Set background image for vertical menu',
				'parent'        => $header_meta_box
			)
		);

		optimize_mikado_add_meta_box_field(
			array(
				'name'          => 'mkdf_disable_vertical_header_background_image_meta',
				'type'          => 'yesno',
				'default_value' => 'no',
				'label'         => 'Disable Background Image',
				'description'   => 'Enabling this option will hide background image in Vertical Menu',
				'parent'        => $header_meta_box
			)
		);

		break;
}

if(optimize_mikado_options()->getOptionValue('header_type') != 'header-vertical') {
	optimize_mikado_add_meta_box_field(
		array(
			'name'            => 'mkdf_scroll_amount_for_sticky_meta',
			'type'            => 'text',
			'label'           => 'Scroll amount for sticky header appearance',
			'description'     => 'Define scroll amount for sticky header appearance',
			'parent'          => $header_meta_box,
			'args'            => array(
				'col_width' => 2,
				'suffix'    => 'px'
			),
			'hidden_property' => 'mkdf_header_behaviour',
			'hidden_values'   => array("sticky-header-on-scroll-up", "fixed-on-scroll")
		)
	);

	optimize_mikado_add_admin_section_title(array(
		'name'   => 'top_bar_section_title',
		'parent' => $header_meta_box,
		'title'  => 'Top Bar'
	));

	$top_bar_global_option      = optimize_mikado_options()->getOptionValue('top_bar');
	$top_bar_default_dependency = array(
		'' => '#mkdf_top_bar_container_no_style'
	);

	$top_bar_show_array = array(
		'yes' => '#mkdf_top_bar_container_no_style'
	);

	$top_bar_hide_array = array(
		'no' => '#mkdf_top_bar_container_no_style'
	);

	if($top_bar_global_option === 'yes') {
		$top_bar_show_array = array_merge($top_bar_show_array, $top_bar_default_dependency);
	} else {
		$top_bar_hide_array = array_merge($top_bar_hide_array, $top_bar_default_dependency);
	}

	optimize_mikado_add_meta_box_field(array(
		'name'          => 'mkdf_top_bar_meta',
		'type'          => 'select',
		'label'         => 'Enable Top Bar on This Page',
		'description'   => 'Enabling this option will enable top bar on this page',
		'parent'        => $header_meta_box,
		'default_value' => '',
		'options'       => array(
			''    => 'Default',
			'yes' => 'Yes',
			'no'  => 'No'
		),
		'args'          => array(
			'dependence' => true,
			'show'       => $top_bar_show_array,
			'hide'       => $top_bar_hide_array
		)
	));

	$top_bar_container = optimize_mikado_add_admin_container_no_style(array(
		'name'            => 'top_bar_container_no_style',
		'parent'          => $header_meta_box,
		'hidden_property' => 'top_bar',
		'hidden_value'    => 'no'
	));

	optimize_mikado_add_meta_box_field(array(
		'name'    => 'mkdf_top_bar_skin_meta',
		'type'    => 'select',
		'label'   => 'Top Bar Skin',
		'options' => array(
			''      => 'Default',
			'light' => 'Light',
			'dark'  => 'Dark'
		),
		'parent'  => $top_bar_container
	));

	optimize_mikado_add_meta_box_field(array(
		'name'   => 'mkdf_top_bar_background_color_meta',
		'type'   => 'color',
		'label'  => 'Top Bar Background Color',
		'parent' => $top_bar_container
	));

	optimize_mikado_add_meta_box_field(array(
		'name'          => 'mkdf_top_bar_social_icon_hover_disabled_meta',
		'type'          => 'yesno',
		'label'         => 'Disable Hover for Social Icons',
		'description'   => 'Choose whether to disable hover on social icons placed in top bar area',
		'parent'        => $top_bar_container,
		'default_value' => 'no'
	));
}
