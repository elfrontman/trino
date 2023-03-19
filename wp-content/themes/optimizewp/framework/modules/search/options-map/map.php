<?php

if(!function_exists('optimize_mikado_search_options_map')) {

	function optimize_mikado_search_options_map() {

		optimize_mikado_add_admin_page(
			array(
				'slug'  => '_search_page',
				'title' => 'Search',
				'icon'  => 'fa fa-search'
			)
		);

		$search_panel = optimize_mikado_add_admin_panel(
			array(
				'title' => 'Search',
				'name'  => 'search',
				'page'  => '_search_page'
			)
		);

		optimize_mikado_add_admin_field(
			array(
				'parent'        => $search_panel,
				'type'          => 'select',
				'name'          => 'search_type',
				'default_value' => 'search-dropdown',
				'label'         => 'Mikado Search Type',
				'description'   => "Choose a type of Mikado search bar",
				'options'       => array(
					'search-dropdown' => 'Search Dropdown'
				)
			)
		);

		optimize_mikado_add_admin_field(
			array(
				'parent'        => $search_panel,
				'type'          => 'select',
				'name'          => 'search_icon_pack',
				'default_value' => 'font_awesome',
				'label'         => 'Search Icon Pack',
				'description'   => 'Choose icon pack for search icon',
				'options'       => optimize_mikado_icon_collections()->getIconCollectionsExclude(array(
					'linea_icons',
					'simple_line_icons',
					'dripicons'
				))
			)
		);

		optimize_mikado_add_admin_field(
			array(
				'parent'        => $search_panel,
				'type'          => 'yesno',
				'name'          => 'search_in_grid',
				'default_value' => 'yes',
				'label'         => 'Search area in grid',
				'description'   => 'Set search area to be in grid',
			)
		);

		optimize_mikado_add_admin_section_title(
			array(
				'parent' => $search_panel,
				'name'   => 'initial_header_icon_title',
				'title'  => 'Initial Search Icon in Header'
			)
		);

		optimize_mikado_add_admin_field(
			array(
				'parent'        => $search_panel,
				'type'          => 'text',
				'name'          => 'header_search_icon_size',
				'default_value' => '',
				'label'         => 'Icon Size',
				'description'   => 'Set size for icon',
				'args'          => array(
					'col_width' => 3,
					'suffix'    => 'px'
				)
			)
		);

		$search_icon_color_group = optimize_mikado_add_admin_group(
			array(
				'parent'      => $search_panel,
				'title'       => 'Icon Colors',
				'description' => 'Define color style for icon',
				'name'        => 'search_icon_color_group'
			)
		);

		$search_icon_color_row = optimize_mikado_add_admin_row(
			array(
				'parent' => $search_icon_color_group,
				'name'   => 'search_icon_color_row'
			)
		);

		optimize_mikado_add_admin_field(
			array(
				'parent' => $search_icon_color_row,
				'type'   => 'colorsimple',
				'name'   => 'header_search_icon_color',
				'label'  => 'Color'
			)
		);
		optimize_mikado_add_admin_field(
			array(
				'parent' => $search_icon_color_row,
				'type'   => 'colorsimple',
				'name'   => 'header_search_icon_hover_color',
				'label'  => 'Hover Color'
			)
		);
		optimize_mikado_add_admin_field(
			array(
				'parent' => $search_icon_color_row,
				'type'   => 'colorsimple',
				'name'   => 'header_light_search_icon_color',
				'label'  => 'Light Header Icon Color'
			)
		);
		optimize_mikado_add_admin_field(
			array(
				'parent' => $search_icon_color_row,
				'type'   => 'colorsimple',
				'name'   => 'header_light_search_icon_hover_color',
				'label'  => 'Light Header Icon Hover Color'
			)
		);

		$search_icon_color_row2 = optimize_mikado_add_admin_row(
			array(
				'parent' => $search_icon_color_group,
				'name'   => 'search_icon_color_row2',
				'next'   => true
			)
		);

		optimize_mikado_add_admin_field(
			array(
				'parent' => $search_icon_color_row2,
				'type'   => 'colorsimple',
				'name'   => 'header_dark_search_icon_color',
				'label'  => 'Dark Header Icon Color'
			)
		);
		optimize_mikado_add_admin_field(
			array(
				'parent' => $search_icon_color_row2,
				'type'   => 'colorsimple',
				'name'   => 'header_dark_search_icon_hover_color',
				'label'  => 'Dark Header Icon Hover Color'
			)
		);


		$search_icon_background_group = optimize_mikado_add_admin_group(
			array(
				'parent'      => $search_panel,
				'title'       => 'Icon Background Style',
				'description' => 'Define background style for icon',
				'name'        => 'search_icon_background_group'
			)
		);

		$search_icon_background_row = optimize_mikado_add_admin_row(
			array(
				'parent' => $search_icon_background_group,
				'name'   => 'search_icon_background_row'
			)
		);

		optimize_mikado_add_admin_field(
			array(
				'parent'        => $search_icon_background_row,
				'type'          => 'colorsimple',
				'name'          => 'search_icon_background_color',
				'default_value' => '',
				'label'         => 'Background Color',
			)
		);

		optimize_mikado_add_admin_field(
			array(
				'parent'        => $search_icon_background_row,
				'type'          => 'colorsimple',
				'name'          => 'search_icon_background_hover_color',
				'default_value' => '',
				'label'         => 'Background Hover Color',
			)
		);

		optimize_mikado_add_admin_field(
			array(
				'parent'        => $search_panel,
				'type'          => 'yesno',
				'name'          => 'enable_search_icon_text',
				'default_value' => 'no',
				'label'         => 'Enable Search Icon Text',
				'description'   => "Enable this option to show 'Search' text next to search icon in header",
				'args'          => array(
					'dependence'             => true,
					'dependence_hide_on_yes' => '',
					'dependence_show_on_yes' => '#mkdf_enable_search_icon_text_container'
				)
			)
		);

		$enable_search_icon_text_container = optimize_mikado_add_admin_container(
			array(
				'parent'          => $search_panel,
				'name'            => 'enable_search_icon_text_container',
				'hidden_property' => 'enable_search_icon_text',
				'hidden_value'    => 'no'
			)
		);

		$enable_search_icon_text_group = optimize_mikado_add_admin_group(
			array(
				'parent'      => $enable_search_icon_text_container,
				'title'       => 'Search Icon Text',
				'name'        => 'enable_search_icon_text_group',
				'description' => 'Define Style for Search Icon Text'
			)
		);

		$enable_search_icon_text_row = optimize_mikado_add_admin_row(
			array(
				'parent' => $enable_search_icon_text_group,
				'name'   => 'enable_search_icon_text_row'
			)
		);

		optimize_mikado_add_admin_field(
			array(
				'parent'        => $enable_search_icon_text_row,
				'type'          => 'colorsimple',
				'name'          => 'search_icon_text_color',
				'label'         => 'Text Color',
				'default_value' => ''
			)
		);

		optimize_mikado_add_admin_field(
			array(
				'parent'        => $enable_search_icon_text_row,
				'type'          => 'colorsimple',
				'name'          => 'search_icon_text_color_hover',
				'label'         => 'Text Hover Color',
				'default_value' => ''
			)
		);

		optimize_mikado_add_admin_field(
			array(
				'parent'        => $enable_search_icon_text_row,
				'type'          => 'textsimple',
				'name'          => 'search_icon_text_fontsize',
				'label'         => 'Font Size',
				'default_value' => '',
				'args'          => array(
					'suffix' => 'px'
				)
			)
		);

		optimize_mikado_add_admin_field(
			array(
				'parent'        => $enable_search_icon_text_row,
				'type'          => 'textsimple',
				'name'          => 'search_icon_text_lineheight',
				'label'         => 'Line Height',
				'default_value' => '',
				'args'          => array(
					'suffix' => 'px'
				)
			)
		);

		$enable_search_icon_text_row2 = optimize_mikado_add_admin_row(
			array(
				'parent' => $enable_search_icon_text_group,
				'name'   => 'enable_search_icon_text_row2',
				'next'   => true
			)
		);

		optimize_mikado_add_admin_field(
			array(
				'parent'        => $enable_search_icon_text_row2,
				'type'          => 'selectblanksimple',
				'name'          => 'search_icon_text_texttransform',
				'label'         => 'Text Transform',
				'default_value' => '',
				'options'       => optimize_mikado_get_text_transform_array()
			)
		);

		optimize_mikado_add_admin_field(
			array(
				'parent'        => $enable_search_icon_text_row2,
				'type'          => 'fontsimple',
				'name'          => 'search_icon_text_google_fonts',
				'label'         => 'Font Family',
				'default_value' => '-1',
			)
		);

		optimize_mikado_add_admin_field(
			array(
				'parent'        => $enable_search_icon_text_row2,
				'type'          => 'selectblanksimple',
				'name'          => 'search_icon_text_fontstyle',
				'label'         => 'Font Style',
				'default_value' => '',
				'options'       => optimize_mikado_get_font_style_array(),
			)
		);

		optimize_mikado_add_admin_field(
			array(
				'parent'        => $enable_search_icon_text_row2,
				'type'          => 'selectblanksimple',
				'name'          => 'search_icon_text_fontweight',
				'label'         => 'Font Weight',
				'default_value' => '',
				'options'       => optimize_mikado_get_font_weight_array(),
			)
		);

		$enable_search_icon_text_row3 = optimize_mikado_add_admin_row(
			array(
				'parent' => $enable_search_icon_text_group,
				'name'   => 'enable_search_icon_text_row3',
				'next'   => true
			)
		);

		optimize_mikado_add_admin_field(
			array(
				'parent'        => $enable_search_icon_text_row3,
				'type'          => 'textsimple',
				'name'          => 'search_icon_text_letterspacing',
				'label'         => 'Letter Spacing',
				'default_value' => '',
				'args'          => array(
					'suffix' => 'px'
				)
			)
		);

		$search_icon_spacing_group = optimize_mikado_add_admin_group(
			array(
				'parent'      => $search_panel,
				'title'       => 'Icon Spacing',
				'description' => 'Define padding and margins for Search icon',
				'name'        => 'search_icon_spacing_group'
			)
		);

		$search_icon_spacing_row = optimize_mikado_add_admin_row(
			array(
				'parent' => $search_icon_spacing_group,
				'name'   => 'search_icon_spacing_row'
			)
		);

		optimize_mikado_add_admin_field(
			array(
				'parent'        => $search_icon_spacing_row,
				'type'          => 'textsimple',
				'name'          => 'search_padding_left',
				'default_value' => '',
				'label'         => 'Padding Left',
				'args'          => array(
					'suffix' => 'px'
				)
			)
		);

		optimize_mikado_add_admin_field(
			array(
				'parent'        => $search_icon_spacing_row,
				'type'          => 'textsimple',
				'name'          => 'search_padding_right',
				'default_value' => '',
				'label'         => 'Padding Right',
				'args'          => array(
					'suffix' => 'px'
				)
			)
		);

		optimize_mikado_add_admin_field(
			array(
				'parent'        => $search_icon_spacing_row,
				'type'          => 'textsimple',
				'name'          => 'search_margin_left',
				'default_value' => '',
				'label'         => 'Margin Left',
				'args'          => array(
					'suffix' => 'px'
				)
			)
		);

		optimize_mikado_add_admin_field(
			array(
				'parent'        => $search_icon_spacing_row,
				'type'          => 'textsimple',
				'name'          => 'search_margin_right',
				'default_value' => '',
				'label'         => 'Margin Right',
				'args'          => array(
					'suffix' => 'px'
				)
			)
		);
	}

	add_action('optimize_mikado_options_map', 'optimize_mikado_search_options_map', 5);

}