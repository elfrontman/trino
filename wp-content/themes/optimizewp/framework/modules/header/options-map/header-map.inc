<?php

if(!function_exists('optimize_mikado_header_options_map')) {

	function optimize_mikado_header_options_map() {

		optimize_mikado_add_admin_page(
			array(
				'slug'  => '_header_page',
				'title' => 'Header',
				'icon'  => 'fa fa-header'
			)
		);

		$panel_header = optimize_mikado_add_admin_panel(
			array(
				'page'  => '_header_page',
				'name'  => 'panel_header',
				'title' => 'Header'
			)
		);

		optimize_mikado_add_admin_field(
			array(
				'parent'        => $panel_header,
				'type'          => 'radiogroup',
				'name'          => 'header_type',
				'default_value' => 'header-standard',
				'label'         => 'Choose Header Type',
				'description'   => 'Select the type of header you would like to use',
				'options'       => array(
					'header-standard' => array(
						'image' => MIKADO_FRAMEWORK_ROOT.'/admin/assets/img/header.png'
					)
				),
				'args'          => array(
					'use_images'  => true,
					'hide_labels' => true,
					'dependence'  => true,
					'show'        => array(
						'header-standard' => '#mkdf_panel_header_standard,#mkdf_header_behaviour,#mkdf_panel_fixed_header,#mkdf_panel_sticky_header,#mkdf_panel_main_menu'
					),
					'hide'        => array(
						'header-standard' => '#mkdf_panel_header_vertical,#mkdf_panel_vertical_main_menu'
					)
				)
			)
		);

		optimize_mikado_add_admin_field(
			array(
				'parent'          => $panel_header,
				'type'            => 'select',
				'name'            => 'header_behaviour',
				'default_value'   => 'sticky-header-on-scroll-up',
				'label'           => 'Choose Header behaviour',
				'description'     => 'Select the behaviour of header when you scroll down to page',
				'options'         => array(
					'sticky-header-on-scroll-up'      => 'Sticky on scrol up',
					'sticky-header-on-scroll-down-up' => 'Sticky on scrol up/down',
					'fixed-on-scroll'                 => 'Fixed on scroll'
				),
				'hidden_property' => 'header_type',
				'hidden_value'    => '',
				'hidden_values'   => array('header-vertical'),
				'args'            => array(
					'dependence' => true,
					'show'       => array(
						'sticky-header-on-scroll-up'      => '#mkdf_panel_sticky_header',
						'sticky-header-on-scroll-down-up' => '#mkdf_panel_sticky_header',
						'fixed-on-scroll'                 => '#mkdf_panel_fixed_header'
					),
					'hide'       => array(
						'sticky-header-on-scroll-up'      => '#mkdf_panel_fixed_header',
						'sticky-header-on-scroll-down-up' => '#mkdf_panel_fixed_header',
						'fixed-on-scroll'                 => '#mkdf_panel_sticky_header',
					)
				)
			)
		);

		optimize_mikado_add_admin_field(
			array(
				'name'          => 'top_bar',
				'type'          => 'yesno',
				'default_value' => 'no',
				'label'         => 'Top Bar',
				'description'   => 'Enabling this option will show top bar area',
				'parent'        => $panel_header,
				'args'          => array(
					"dependence"             => true,
					"dependence_hide_on_yes" => "",
					"dependence_show_on_yes" => "#mkdf_top_bar_container"
				)
			)
		);

		$top_bar_container = optimize_mikado_add_admin_container(array(
			'name'            => 'top_bar_container',
			'parent'          => $panel_header,
			'hidden_property' => 'top_bar',
			'hidden_value'    => 'no'
		));

		optimize_mikado_add_admin_field(
			array(
				'parent'        => $top_bar_container,
				'type'          => 'select',
				'name'          => 'top_bar_layout',
				'default_value' => 'three-columns',
				'label'         => 'Choose top bar layout',
				'description'   => 'Select the layout for top bar',
				'options'       => array(
					'two-columns'   => 'Two columns',
					'three-columns' => 'Three columns'
				),
				'args'          => array(
					'dependence' => true,
					'hide'       => array(
						'two-columns'   => '#mkdf_top_bar_layout_container',
						'three-columns' => '#mkdf_top_bar_two_columns_layout_container'
					),
					'show'       => array(
						'two-columns'   => '#mkdf_top_bar_two_columns_layout_container',
						'three-columns' => '#mkdf_top_bar_layout_container'
					)
				)
			)
		);

		$top_bar_layout_container = optimize_mikado_add_admin_container(array(
			'name'            => 'top_bar_layout_container',
			'parent'          => $top_bar_container,
			'hidden_property' => 'top_bar_layout',
			'hidden_value'    => '',
			'hidden_values'   => array('two-columns'),
		));

		optimize_mikado_add_admin_field(
			array(
				'parent'        => $top_bar_layout_container,
				'type'          => 'select',
				'name'          => 'top_bar_column_widths',
				'default_value' => '30-30-30',
				'label'         => 'Choose column widths',
				'description'   => '',
				'options'       => array(
					'30-30-30' => '33% - 33% - 33%',
					'25-50-25' => '25% - 50% - 25%'
				)
			)
		);

		$top_bar_two_columns_layout = optimize_mikado_add_admin_container(array(
			'name'            => 'top_bar_two_columns_layout_container',
			'parent'          => $top_bar_container,
			'hidden_property' => 'top_bar_layout',
			'hidden_value'    => '',
			'hidden_values'   => array('three-columns'),
		));

		optimize_mikado_add_admin_field(
			array(
				'parent'        => $top_bar_two_columns_layout,
				'type'          => 'select',
				'name'          => 'top_bar_two_column_widths',
				'default_value' => '50-50',
				'label'         => 'Choose column widths',
				'description'   => '',
				'options'       => array(
					'50-50' => '50% - 50%',
					'33-66' => '33% - 66%',
					'66-33' => '66% - 33%'
				)
			)
		);

		optimize_mikado_add_admin_field(
			array(
				'name'          => 'top_bar_in_grid',
				'type'          => 'yesno',
				'default_value' => 'yes',
				'label'         => 'Top Bar in grid',
				'description'   => 'Set top bar content to be in grid',
				'parent'        => $top_bar_container,
				'args'          => array(
					"dependence"             => true,
					"dependence_hide_on_yes" => "",
					"dependence_show_on_yes" => "#mkdf_top_bar_in_grid_container"
				)
			)
		);

		$top_bar_in_grid_container = optimize_mikado_add_admin_container(array(
			'name'            => 'top_bar_in_grid_container',
			'parent'          => $top_bar_container,
			'hidden_property' => 'top_bar_in_grid',
			'hidden_value'    => 'no'
		));

		optimize_mikado_add_admin_field(array(
			'name'        => 'top_bar_grid_background_color',
			'type'        => 'color',
			'label'       => 'Grid Background Color',
			'description' => 'Set grid background color for top bar',
			'parent'      => $top_bar_in_grid_container
		));


		optimize_mikado_add_admin_field(array(
			'name'        => 'top_bar_grid_background_transparency',
			'type'        => 'text',
			'label'       => 'Grid Background Transparency',
			'description' => 'Set grid background transparency for top bar',
			'parent'      => $top_bar_in_grid_container,
			'args'        => array('col_width' => 3)
		));

		optimize_mikado_add_admin_field(array(
			'name'        => 'top_bar_background_color',
			'type'        => 'color',
			'label'       => 'Background Color',
			'description' => 'Set background color for top bar',
			'parent'      => $top_bar_container
		));

		optimize_mikado_add_admin_field(array(
			'name'        => 'top_bar_background_transparency',
			'type'        => 'text',
			'label'       => 'Background Transparency',
			'description' => 'Set background transparency for top bar',
			'parent'      => $top_bar_container,
			'args'        => array('col_width' => 3)
		));

		optimize_mikado_add_admin_field(array(
			'name'        => 'top_bar_height',
			'type'        => 'text',
			'label'       => 'Top bar height',
			'description' => 'Enter top bar height (Default is 40px)',
			'parent'      => $top_bar_container,
			'args'        => array(
				'col_width' => 2,
				'suffix'    => 'px'
			)
		));

		optimize_mikado_add_admin_field(
			array(
				'parent'        => $panel_header,
				'type'          => 'select',
				'name'          => 'header_style',
				'default_value' => '',
				'label'         => 'Header Skin',
				'description'   => 'Choose a header style to make header elements (logo, main menu, side menu button) in that predefined style',
				'options'       => array(
					''             => '',
					'light-header' => 'Light',
					'dark-header'  => 'Dark'
				)
			)
		);

		optimize_mikado_add_admin_field(
			array(
				'parent'        => $panel_header,
				'type'          => 'yesno',
				'name'          => 'enable_header_style_on_scroll',
				'default_value' => 'no',
				'label'         => 'Enable Header Style on Scroll',
				'description'   => 'Enabling this option, header will change style depending on row settings for dark/light style',
			)
		);

		$panel_header_standard = optimize_mikado_add_admin_panel(
			array(
				'page'            => '_header_page',
				'name'            => 'panel_header_standard',
				'title'           => 'Header Standard',
				'hidden_property' => 'header_type',
				'hidden_value'    => '',
				'hidden_values'   => array(
					'header-vertical'
				)
			)
		);

		optimize_mikado_add_admin_section_title(
			array(
				'parent' => $panel_header_standard,
				'name'   => 'menu_area_title',
				'title'  => 'Menu Area'
			)
		);

		optimize_mikado_add_admin_field(
			array(
				'parent'        => $panel_header_standard,
				'type'          => 'yesno',
				'name'          => 'menu_area_in_grid_header_standard',
				'default_value' => 'yes',
				'label'         => 'Header in grid',
				'description'   => 'Set header content to be in grid',
				'args'          => array(
					'dependence'             => true,
					'dependence_hide_on_yes' => '',
					'dependence_show_on_yes' => '#mkdf_menu_area_in_grid_header_standard_container'
				)
			)
		);

		$menu_area_in_grid_header_standard_container = optimize_mikado_add_admin_container(
			array(
				'parent'          => $panel_header_standard,
				'name'            => 'menu_area_in_grid_header_standard_container',
				'hidden_property' => 'menu_area_in_grid_header_standard',
				'hidden_value'    => 'no'
			)
		);

		optimize_mikado_add_admin_field(
			array(
				'parent'        => $menu_area_in_grid_header_standard_container,
				'type'          => 'color',
				'name'          => 'menu_area_grid_background_color_header_standard',
				'default_value' => '',
				'label'         => 'Grid Background color',
				'description'   => 'Set grid background color for header area',
			)
		);

		optimize_mikado_add_admin_field(
			array(
				'parent'        => $menu_area_in_grid_header_standard_container,
				'type'          => 'text',
				'name'          => 'menu_area_grid_background_transparency_header_standard',
				'default_value' => '',
				'label'         => 'Grid background transparency',
				'description'   => 'Set grid background transparency for header',
				'args'          => array(
					'col_width' => 3
				)
			)
		);

		optimize_mikado_add_admin_field(
			array(
				'parent'        => $panel_header_standard,
				'type'          => 'color',
				'name'          => 'menu_area_background_color_header_standard',
				'default_value' => '',
				'label'         => 'Background color',
				'description'   => 'Set background color for header'
			)
		);

		optimize_mikado_add_admin_field(
			array(
				'parent'        => $panel_header_standard,
				'type'          => 'text',
				'name'          => 'menu_area_background_transparency_header_standard',
				'default_value' => '',
				'label'         => 'Background transparency',
				'description'   => 'Set background transparency for header',
				'args'          => array(
					'col_width' => 3
				)
			)
		);

		optimize_mikado_add_admin_field(
			array(
				'parent'        => $panel_header_standard,
				'type'          => 'text',
				'name'          => 'menu_area_height_header_standard',
				'default_value' => '',
				'label'         => 'Height',
				'description'   => 'Enter header height (default is 60px)',
				'args'          => array(
					'col_width' => 3,
					'suffix'    => 'px'
				)
			)
		);

		$panel_header_vertical = optimize_mikado_add_admin_panel(
			array(
				'page'            => '_header_page',
				'name'            => 'panel_header_vertical',
				'title'           => 'Header Vertical',
				'hidden_property' => 'header_type',
				'hidden_value'    => '',
				'hidden_values'   => array(
					'header-standard'
				)
			)
		);

		optimize_mikado_add_admin_field(array(
			'name'        => 'vertical_header_background_color',
			'type'        => 'color',
			'label'       => 'Background Color',
			'description' => 'Set background color for vertical menu',
			'parent'      => $panel_header_vertical
		));

		optimize_mikado_add_admin_field(array(
			'name'        => 'vertical_header_transparency',
			'type'        => 'text',
			'label'       => 'Transparency',
			'description' => 'Enter transparency for vertical menu (value from 0 to 1)',
			'parent'      => $panel_header_vertical,
			'args'        => array(
				'col_width' => 1
			)
		));

		optimize_mikado_add_admin_field(
			array(
				'name'          => 'vertical_header_background_image',
				'type'          => 'image',
				'default_value' => '',
				'label'         => 'Background Image',
				'description'   => 'Set background image for vertical menu',
				'parent'        => $panel_header_vertical
			)
		);

		$panel_sticky_header = optimize_mikado_add_admin_panel(
			array(
				'title'           => 'Sticky Header',
				'name'            => 'panel_sticky_header',
				'page'            => '_header_page',
				'hidden_property' => 'header_behaviour',
				'hidden_values'   => array(
					'fixed-on-scroll'
				)
			)
		);

		optimize_mikado_add_admin_field(
			array(
				'name'        => 'scroll_amount_for_sticky',
				'type'        => 'text',
				'label'       => 'Scroll Amount for Sticky',
				'description' => 'Enter scroll amount for Sticky Menu to appear (deafult is header height)',
				'parent'      => $panel_sticky_header,
				'args'        => array(
					'col_width' => 2,
					'suffix'    => 'px'
				)
			)
		);

		optimize_mikado_add_admin_field(
			array(
				'name'          => 'sticky_header_in_grid',
				'type'          => 'yesno',
				'default_value' => 'yes',
				'label'         => 'Sticky Header in grid',
				'description'   => 'Set sticky header content to be in grid',
				'parent'        => $panel_sticky_header,
				'args'          => array(
					"dependence"             => true,
					"dependence_hide_on_yes" => "",
					"dependence_show_on_yes" => "#mkdf_sticky_header_in_grid_container"
				)
			)
		);

		$sticky_header_in_grid_container = optimize_mikado_add_admin_container(array(
			'name'            => 'sticky_header_in_grid_container',
			'parent'          => $panel_sticky_header,
			'hidden_property' => 'sticky_header_in_grid',
			'hidden_value'    => 'no'
		));

		optimize_mikado_add_admin_field(array(
			'name'        => 'sticky_header_grid_background_color',
			'type'        => 'color',
			'label'       => 'Grid Background Color',
			'description' => 'Set grid background color for sticky header',
			'parent'      => $sticky_header_in_grid_container
		));

		optimize_mikado_add_admin_field(array(
			'name'        => 'sticky_header_grid_transparency',
			'type'        => 'text',
			'label'       => 'Sticky Header Grid Transparency',
			'description' => 'Enter transparency for sticky header grid (value from 0 to 1)',
			'parent'      => $sticky_header_in_grid_container,
			'args'        => array(
				'col_width' => 1
			)
		));

		optimize_mikado_add_admin_field(array(
			'name'        => 'sticky_header_background_color',
			'type'        => 'color',
			'label'       => 'Background Color',
			'description' => 'Set background color for sticky header',
			'parent'      => $panel_sticky_header
		));

		optimize_mikado_add_admin_field(array(
			'name'        => 'sticky_header_transparency',
			'type'        => 'text',
			'label'       => 'Sticky Header Transparency',
			'description' => 'Enter transparency for sticky header (value from 0 to 1)',
			'parent'      => $panel_sticky_header,
			'args'        => array(
				'col_width' => 1
			)
		));

		optimize_mikado_add_admin_field(array(
			'name'        => 'sticky_header_height',
			'type'        => 'text',
			'label'       => 'Sticky Header Height',
			'description' => 'Enter height for sticky header (default is 60px)',
			'parent'      => $panel_sticky_header,
			'args'        => array(
				'col_width' => 2,
				'suffix'    => 'px'
			)
		));

		$group_sticky_header_menu = optimize_mikado_add_admin_group(array(
			'title'       => 'Sticky Header Menu',
			'name'        => 'group_sticky_header_menu',
			'parent'      => $panel_sticky_header,
			'description' => 'Define styles for sticky menu items',
		));

		$row1_sticky_header_menu = optimize_mikado_add_admin_row(array(
			'name'   => 'row1',
			'parent' => $group_sticky_header_menu
		));

		optimize_mikado_add_admin_field(array(
			'name'        => 'sticky_color',
			'type'        => 'colorsimple',
			'label'       => 'Text Color',
			'description' => '',
			'parent'      => $row1_sticky_header_menu
		));

		optimize_mikado_add_admin_field(array(
			'name'        => 'sticky_hovercolor',
			'type'        => 'colorsimple',
			'label'       => 'Hover/Active color',
			'description' => '',
			'parent'      => $row1_sticky_header_menu
		));

		$row2_sticky_header_menu = optimize_mikado_add_admin_row(array(
			'name'   => 'row2',
			'parent' => $group_sticky_header_menu
		));

		optimize_mikado_add_admin_field(
			array(
				'name'          => 'sticky_google_fonts',
				'type'          => 'fontsimple',
				'label'         => 'Font Family',
				'default_value' => '-1',
				'parent'        => $row2_sticky_header_menu,
			)
		);

		optimize_mikado_add_admin_field(
			array(
				'type'          => 'textsimple',
				'name'          => 'sticky_fontsize',
				'label'         => 'Font Size',
				'default_value' => '',
				'parent'        => $row2_sticky_header_menu,
				'args'          => array(
					'suffix' => 'px'
				)
			)
		);

		optimize_mikado_add_admin_field(
			array(
				'type'          => 'textsimple',
				'name'          => 'sticky_lineheight',
				'label'         => 'Line height',
				'default_value' => '',
				'parent'        => $row2_sticky_header_menu,
				'args'          => array(
					'suffix' => 'px'
				)
			)
		);

		optimize_mikado_add_admin_field(
			array(
				'type'          => 'selectblanksimple',
				'name'          => 'sticky_texttransform',
				'label'         => 'Text transform',
				'default_value' => '',
				'options'       => optimize_mikado_get_text_transform_array(),
				'parent'        => $row2_sticky_header_menu
			)
		);

		$row3_sticky_header_menu = optimize_mikado_add_admin_row(array(
			'name'   => 'row3',
			'parent' => $group_sticky_header_menu
		));

		optimize_mikado_add_admin_field(
			array(
				'type'          => 'selectblanksimple',
				'name'          => 'sticky_fontstyle',
				'default_value' => '',
				'label'         => 'Font Style',
				'options'       => optimize_mikado_get_font_style_array(),
				'parent'        => $row3_sticky_header_menu
			)
		);

		optimize_mikado_add_admin_field(
			array(
				'type'          => 'selectblanksimple',
				'name'          => 'sticky_fontweight',
				'default_value' => '',
				'label'         => 'Font Weight',
				'options'       => optimize_mikado_get_font_weight_array(),
				'parent'        => $row3_sticky_header_menu
			)
		);

		optimize_mikado_add_admin_field(
			array(
				'type'          => 'textsimple',
				'name'          => 'sticky_letterspacing',
				'label'         => 'Letter Spacing',
				'default_value' => '',
				'parent'        => $row3_sticky_header_menu,
				'args'          => array(
					'suffix' => 'px'
				)
			)
		);

		$panel_fixed_header = optimize_mikado_add_admin_panel(
			array(
				'title'           => 'Fixed Header',
				'name'            => 'panel_fixed_header',
				'page'            => '_header_page',
				'hidden_property' => 'header_behaviour',
				'hidden_values'   => array('sticky-header-on-scroll-up', 'sticky-header-on-scroll-down-up')
			)
		);

		optimize_mikado_add_admin_field(array(
			'name'          => 'fixed_header_grid_background_color',
			'type'          => 'color',
			'default_value' => '',
			'label'         => 'Grid Background Color',
			'description'   => 'Set grid background color for fixed header',
			'parent'        => $panel_fixed_header
		));

		optimize_mikado_add_admin_field(array(
			'name'          => 'fixed_header_grid_transparency',
			'type'          => 'text',
			'default_value' => '',
			'label'         => 'Header Transparency Grid',
			'description'   => 'Enter transparency for fixed header grid (value from 0 to 1)',
			'parent'        => $panel_fixed_header,
			'args'          => array(
				'col_width' => 1
			)
		));

		optimize_mikado_add_admin_field(array(
			'name'          => 'fixed_header_background_color',
			'type'          => 'color',
			'default_value' => '',
			'label'         => 'Background Color',
			'description'   => 'Set background color for fixed header',
			'parent'        => $panel_fixed_header
		));

		optimize_mikado_add_admin_field(array(
			'name'        => 'fixed_header_transparency',
			'type'        => 'text',
			'label'       => 'Header Transparency',
			'description' => 'Enter transparency for fixed header (value from 0 to 1)',
			'parent'      => $panel_fixed_header,
			'args'        => array(
				'col_width' => 1
			)
		));


		$panel_main_menu = optimize_mikado_add_admin_panel(
			array(
				'title'           => 'Main Menu',
				'name'            => 'panel_main_menu',
				'page'            => '_header_page',
				'hidden_property' => 'header_type',
				'hidden_values'   => array('header-vertical')
			)
		);

		optimize_mikado_add_admin_section_title(
			array(
				'parent' => $panel_main_menu,
				'name'   => 'main_menu_area_title',
				'title'  => 'Main Menu General Settings'
			)
		);

		$drop_down_group = optimize_mikado_add_admin_group(
			array(
				'parent'      => $panel_main_menu,
				'name'        => 'drop_down_group',
				'title'       => 'Main Dropdown Menu',
				'description' => 'Choose a color and transparency for the main menu background (0 = fully transparent, 1 = opaque)'
			)
		);

		$drop_down_row1 = optimize_mikado_add_admin_row(
			array(
				'parent' => $drop_down_group,
				'name'   => 'drop_down_row1',
			)
		);

		optimize_mikado_add_admin_field(
			array(
				'parent'        => $drop_down_row1,
				'type'          => 'colorsimple',
				'name'          => 'dropdown_background_color',
				'default_value' => '',
				'label'         => 'Background Color',
			)
		);

		optimize_mikado_add_admin_field(
			array(
				'parent'        => $drop_down_row1,
				'type'          => 'textsimple',
				'name'          => 'dropdown_background_transparency',
				'default_value' => '',
				'label'         => 'Transparency',
			)
		);

		$drop_down_padding_group = optimize_mikado_add_admin_group(
			array(
				'parent'      => $panel_main_menu,
				'name'        => 'drop_down_padding_group',
				'title'       => 'Main Dropdown Menu Padding',
				'description' => 'Choose a top/bottom padding for dropdown menu'
			)
		);

		$drop_down_padding_row = optimize_mikado_add_admin_row(
			array(
				'parent' => $drop_down_padding_group,
				'name'   => 'drop_down_padding_row',
			)
		);

		optimize_mikado_add_admin_field(
			array(
				'parent'        => $drop_down_padding_row,
				'type'          => 'textsimple',
				'name'          => 'dropdown_top_padding',
				'default_value' => '',
				'label'         => 'Top Padding',
				'args'          => array(
					'suffix' => 'px'
				)
			)
		);

		optimize_mikado_add_admin_field(
			array(
				'parent'        => $drop_down_padding_row,
				'type'          => 'textsimple',
				'name'          => 'dropdown_bottom_padding',
				'default_value' => '',
				'label'         => 'Bottom Padding',
				'args'          => array(
					'suffix' => 'px'
				)
			)
		);

		optimize_mikado_add_admin_field(
			array(
				'parent'        => $panel_main_menu,
				'type'          => 'select',
				'name'          => 'menu_dropdown_appearance',
				'default_value' => 'default',
				'label'         => 'Main Dropdown Menu Appearance',
				'description'   => 'Choose appearance for dropdown menu',
				'options'       => array(
					'dropdown-default'           => 'Default',
					'dropdown-slide-from-bottom' => 'Slide From Bottom',
					'dropdown-slide-from-top'    => 'Slide From Top',
					'dropdown-animate-height'    => 'Animate Height',
					'dropdown-slide-from-left'   => 'Slide From Left'
				)
			)
		);

		optimize_mikado_add_admin_field(
			array(
				'parent'        => $panel_main_menu,
				'type'          => 'text',
				'name'          => 'dropdown_top_position',
				'default_value' => '',
				'label'         => 'Dropdown position',
				'description'   => 'Enter value in percentage of entire header height',
				'args'          => array(
					'col_width' => 3,
					'suffix'    => '%'
				)
			)
		);

		optimize_mikado_add_admin_field(
			array(
				'parent'        => $panel_main_menu,
				'type'          => 'yesno',
				'name'          => 'enable_wide_menu_background',
				'default_value' => 'no',
				'label'         => 'Enable Full Width Background for Wide Dropdown Type',
				'description'   => 'Enabling this option will show full width background  for wide dropdown type',
			)
		);

		$first_level_group = optimize_mikado_add_admin_group(
			array(
				'parent'      => $panel_main_menu,
				'name'        => 'first_level_group',
				'title'       => '1st Level Menu',
				'description' => 'Define styles for 1st level in Top Navigation Menu'
			)
		);

		$first_level_row1 = optimize_mikado_add_admin_row(
			array(
				'parent' => $first_level_group,
				'name'   => 'first_level_row1'
			)
		);

		optimize_mikado_add_admin_field(
			array(
				'parent'        => $first_level_row1,
				'type'          => 'colorsimple',
				'name'          => 'menu_color',
				'default_value' => '',
				'label'         => 'Text Color',
			)
		);

		optimize_mikado_add_admin_field(
			array(
				'parent'        => $first_level_row1,
				'type'          => 'colorsimple',
				'name'          => 'menu_hovercolor',
				'default_value' => '',
				'label'         => 'Hover Text Color',
			)
		);

		optimize_mikado_add_admin_field(
			array(
				'parent'        => $first_level_row1,
				'type'          => 'colorsimple',
				'name'          => 'menu_activecolor',
				'default_value' => '',
				'label'         => 'Active Text Color',
			)
		);

		$first_level_row2 = optimize_mikado_add_admin_row(
			array(
				'parent' => $first_level_group,
				'name'   => 'first_level_row2',
				'next'   => true
			)
		);

		optimize_mikado_add_admin_field(
			array(
				'parent'        => $first_level_row2,
				'type'          => 'colorsimple',
				'name'          => 'menu_text_background_color',
				'default_value' => '',
				'label'         => 'Text Background Color',
			)
		);

		optimize_mikado_add_admin_field(
			array(
				'parent'        => $first_level_row2,
				'type'          => 'colorsimple',
				'name'          => 'menu_hover_background_color',
				'default_value' => '',
				'label'         => 'Hover Text Background Color',
			)
		);

		optimize_mikado_add_admin_field(
			array(
				'parent'        => $first_level_row2,
				'type'          => 'colorsimple',
				'name'          => 'menu_active_background_color',
				'default_value' => '',
				'label'         => 'Active Text Background Color',
			)
		);

		$first_level_row3 = optimize_mikado_add_admin_row(
			array(
				'parent' => $first_level_group,
				'name'   => 'first_level_row3',
				'next'   => true
			)
		);

		optimize_mikado_add_admin_field(
			array(
				'parent'        => $first_level_row3,
				'type'          => 'colorsimple',
				'name'          => 'menu_light_hovercolor',
				'default_value' => '',
				'label'         => 'Light Menu Hover Text Color',
			)
		);

		optimize_mikado_add_admin_field(
			array(
				'parent'        => $first_level_row3,
				'type'          => 'colorsimple',
				'name'          => 'menu_light_activecolor',
				'default_value' => '',
				'label'         => 'Light Menu Active Text Color',
			)
		);

		optimize_mikado_add_admin_field(
			array(
				'parent'        => $first_level_row3,
				'type'          => 'colorsimple',
				'name'          => 'menu_light_border_color',
				'default_value' => '',
				'label'         => 'Light Menu Border Hover/Active Color',
			)
		);

		$first_level_row4 = optimize_mikado_add_admin_row(
			array(
				'parent' => $first_level_group,
				'name'   => 'first_level_row4',
				'next'   => true
			)
		);

		optimize_mikado_add_admin_field(
			array(
				'parent'        => $first_level_row4,
				'type'          => 'colorsimple',
				'name'          => 'menu_dark_hovercolor',
				'default_value' => '',
				'label'         => 'Dark Menu Hover Text Color',
			)
		);

		optimize_mikado_add_admin_field(
			array(
				'parent'        => $first_level_row4,
				'type'          => 'colorsimple',
				'name'          => 'menu_dark_activecolor',
				'default_value' => '',
				'label'         => 'Dark Menu Active Text Color',
			)
		);

		optimize_mikado_add_admin_field(
			array(
				'parent'        => $first_level_row4,
				'type'          => 'colorsimple',
				'name'          => 'menu_dark_border_color',
				'default_value' => '',
				'label'         => 'Dark Menu Border Hover/Active Color',
			)
		);

		$first_level_row5 = optimize_mikado_add_admin_row(
			array(
				'parent' => $first_level_group,
				'name'   => 'first_level_row5',
				'next'   => true
			)
		);

		optimize_mikado_add_admin_field(
			array(
				'parent'        => $first_level_row5,
				'type'          => 'fontsimple',
				'name'          => 'menu_google_fonts',
				'default_value' => '-1',
				'label'         => 'Font Family',
			)
		);

		optimize_mikado_add_admin_field(
			array(
				'parent'        => $first_level_row5,
				'type'          => 'textsimple',
				'name'          => 'menu_fontsize',
				'default_value' => '',
				'label'         => 'Font Size',
				'args'          => array(
					'suffix' => 'px'
				)
			)
		);

		optimize_mikado_add_admin_field(
			array(
				'parent'        => $first_level_row5,
				'type'          => 'textsimple',
				'name'          => 'menu_hover_background_color_transparency',
				'default_value' => '',
				'label'         => 'Hover Background Color Transparency',
			)
		);

		optimize_mikado_add_admin_field(
			array(
				'parent'        => $first_level_row5,
				'type'          => 'textsimple',
				'name'          => 'menu_active_background_color_transparency',
				'default_value' => '',
				'label'         => 'Active Background Color Transparency',
			)
		);

		$first_level_row6 = optimize_mikado_add_admin_row(
			array(
				'parent' => $first_level_group,
				'name'   => 'first_level_row6',
				'next'   => true
			)
		);

		optimize_mikado_add_admin_field(
			array(
				'parent'        => $first_level_row6,
				'type'          => 'selectblanksimple',
				'name'          => 'menu_fontstyle',
				'default_value' => '',
				'label'         => 'Font Style',
				'options'       => optimize_mikado_get_font_style_array()
			)
		);

		optimize_mikado_add_admin_field(
			array(
				'parent'        => $first_level_row6,
				'type'          => 'selectblanksimple',
				'name'          => 'menu_fontweight',
				'default_value' => '',
				'label'         => 'Font Weight',
				'options'       => optimize_mikado_get_font_weight_array()
			)
		);

		optimize_mikado_add_admin_field(
			array(
				'parent'        => $first_level_row6,
				'type'          => 'textsimple',
				'name'          => 'menu_letterspacing',
				'default_value' => '',
				'label'         => 'Letter Spacing',
				'args'          => array(
					'suffix' => 'px'
				)
			)
		);

		optimize_mikado_add_admin_field(
			array(
				'parent'        => $first_level_row6,
				'type'          => 'selectblanksimple',
				'name'          => 'menu_texttransform',
				'default_value' => '',
				'label'         => 'Text Transform',
				'options'       => optimize_mikado_get_text_transform_array()
			)
		);

		$first_level_row7 = optimize_mikado_add_admin_row(
			array(
				'parent' => $first_level_group,
				'name'   => 'first_level_row7',
				'next'   => true
			)
		);

		optimize_mikado_add_admin_field(
			array(
				'parent'        => $first_level_row7,
				'type'          => 'textsimple',
				'name'          => 'menu_lineheight',
				'default_value' => '',
				'label'         => 'Line Height',
				'args'          => array(
					'suffix' => 'px'
				)
			)
		);

		optimize_mikado_add_admin_field(
			array(
				'parent'        => $first_level_row7,
				'type'          => 'textsimple',
				'name'          => 'menu_padding_left_right',
				'default_value' => '',
				'label'         => 'Padding Left/Right',
				'args'          => array(
					'suffix' => 'px'
				)
			)
		);

		optimize_mikado_add_admin_field(
			array(
				'parent'        => $first_level_row7,
				'type'          => 'textsimple',
				'name'          => 'menu_margin_left_right',
				'default_value' => '',
				'label'         => 'Margin Left/Right',
				'args'          => array(
					'suffix' => 'px'
				)
			)
		);

		$second_level_group = optimize_mikado_add_admin_group(
			array(
				'parent'      => $panel_main_menu,
				'name'        => 'second_level_group',
				'title'       => '2nd Level Menu',
				'description' => 'Define styles for 2nd level in Top Navigation Menu'
			)
		);

		$second_level_row1 = optimize_mikado_add_admin_row(
			array(
				'parent' => $second_level_group,
				'name'   => 'second_level_row1'
			)
		);

		optimize_mikado_add_admin_field(
			array(
				'parent'        => $second_level_row1,
				'type'          => 'colorsimple',
				'name'          => 'dropdown_color',
				'default_value' => '',
				'label'         => 'Text Color'
			)
		);

		optimize_mikado_add_admin_field(
			array(
				'parent'        => $second_level_row1,
				'type'          => 'colorsimple',
				'name'          => 'dropdown_hovercolor',
				'default_value' => '',
				'label'         => 'Hover/Active Color'
			)
		);

		optimize_mikado_add_admin_field(
			array(
				'parent'        => $second_level_row1,
				'type'          => 'colorsimple',
				'name'          => 'dropdown_background_hovercolor',
				'default_value' => '',
				'label'         => 'Hover/Active Background Color'
			)
		);

		$second_level_row2 = optimize_mikado_add_admin_row(
			array(
				'parent' => $second_level_group,
				'name'   => 'second_level_row2',
				'next'   => true
			)
		);

		optimize_mikado_add_admin_field(
			array(
				'parent'        => $second_level_row2,
				'type'          => 'fontsimple',
				'name'          => 'dropdown_google_fonts',
				'default_value' => '-1',
				'label'         => 'Font Family'
			)
		);

		optimize_mikado_add_admin_field(
			array(
				'parent'        => $second_level_row2,
				'type'          => 'textsimple',
				'name'          => 'dropdown_fontsize',
				'default_value' => '',
				'label'         => 'Font Size',
				'args'          => array(
					'suffix' => 'px'
				)
			)
		);

		optimize_mikado_add_admin_field(
			array(
				'parent'        => $second_level_row2,
				'type'          => 'textsimple',
				'name'          => 'dropdown_lineheight',
				'default_value' => '',
				'label'         => 'Line Height',
				'args'          => array(
					'suffix' => 'px'
				)
			)
		);

		optimize_mikado_add_admin_field(
			array(
				'parent'        => $second_level_row2,
				'type'          => 'textsimple',
				'name'          => 'dropdown_padding_top_bottom',
				'default_value' => '',
				'label'         => 'Padding Top/Bottom',
				'args'          => array(
					'suffix' => 'px'
				)
			)
		);

		$second_level_row3 = optimize_mikado_add_admin_row(
			array(
				'parent' => $second_level_group,
				'name'   => 'second_level_row3',
				'next'   => true
			)
		);

		optimize_mikado_add_admin_field(
			array(
				'parent'        => $second_level_row3,
				'type'          => 'selectblanksimple',
				'name'          => 'dropdown_fontstyle',
				'default_value' => '',
				'label'         => 'Font style',
				'options'       => optimize_mikado_get_font_style_array()
			)
		);

		optimize_mikado_add_admin_field(
			array(
				'parent'        => $second_level_row3,
				'type'          => 'selectblanksimple',
				'name'          => 'dropdown_fontweight',
				'default_value' => '',
				'label'         => 'Font weight',
				'options'       => optimize_mikado_get_font_weight_array()
			)
		);

		optimize_mikado_add_admin_field(
			array(
				'parent'        => $second_level_row3,
				'type'          => 'textsimple',
				'name'          => 'dropdown_letterspacing',
				'default_value' => '',
				'label'         => 'Letter spacing',
				'args'          => array(
					'suffix' => 'px'
				)
			)
		);

		optimize_mikado_add_admin_field(
			array(
				'parent'        => $second_level_row3,
				'type'          => 'selectblanksimple',
				'name'          => 'dropdown_texttransform',
				'default_value' => '',
				'label'         => 'Text Transform',
				'options'       => optimize_mikado_get_text_transform_array()
			)
		);

		$second_level_wide_group = optimize_mikado_add_admin_group(
			array(
				'parent'      => $panel_main_menu,
				'name'        => 'second_level_wide_group',
				'title'       => '2nd Level Wide Menu',
				'description' => 'Define styles for 2nd level in Wide Menu'
			)
		);

		$second_level_wide_row1 = optimize_mikado_add_admin_row(
			array(
				'parent' => $second_level_wide_group,
				'name'   => 'second_level_wide_row1'
			)
		);

		optimize_mikado_add_admin_field(
			array(
				'parent'        => $second_level_wide_row1,
				'type'          => 'colorsimple',
				'name'          => 'dropdown_wide_color',
				'default_value' => '',
				'label'         => 'Text Color'
			)
		);

		optimize_mikado_add_admin_field(
			array(
				'parent'        => $second_level_wide_row1,
				'type'          => 'colorsimple',
				'name'          => 'dropdown_wide_hovercolor',
				'default_value' => '',
				'label'         => 'Hover/Active Color'
			)
		);

		optimize_mikado_add_admin_field(
			array(
				'parent'        => $second_level_wide_row1,
				'type'          => 'colorsimple',
				'name'          => 'dropdown_wide_background_hovercolor',
				'default_value' => '',
				'label'         => 'Hover/Active Background Color'
			)
		);

		$second_level_wide_row2 = optimize_mikado_add_admin_row(
			array(
				'parent' => $second_level_wide_group,
				'name'   => 'second_level_wide_row2',
				'next'   => true
			)
		);

		optimize_mikado_add_admin_field(
			array(
				'parent'        => $second_level_wide_row2,
				'type'          => 'fontsimple',
				'name'          => 'dropdown_wide_google_fonts',
				'default_value' => '-1',
				'label'         => 'Font Family'
			)
		);

		optimize_mikado_add_admin_field(
			array(
				'parent'        => $second_level_wide_row2,
				'type'          => 'textsimple',
				'name'          => 'dropdown_wide_fontsize',
				'default_value' => '',
				'label'         => 'Font Size',
				'args'          => array(
					'suffix' => 'px'
				)
			)
		);

		optimize_mikado_add_admin_field(
			array(
				'parent'        => $second_level_wide_row2,
				'type'          => 'textsimple',
				'name'          => 'dropdown_wide_lineheight',
				'default_value' => '',
				'label'         => 'Line Height',
				'args'          => array(
					'suffix' => 'px'
				)
			)
		);

		optimize_mikado_add_admin_field(
			array(
				'parent'        => $second_level_wide_row2,
				'type'          => 'textsimple',
				'name'          => 'dropdown_wide_padding_top_bottom',
				'default_value' => '',
				'label'         => 'Padding Top/Bottom',
				'args'          => array(
					'suffix' => 'px'
				)
			)
		);

		$second_level_wide_row3 = optimize_mikado_add_admin_row(
			array(
				'parent' => $second_level_wide_group,
				'name'   => 'second_level_wide_row3',
				'next'   => true
			)
		);

		optimize_mikado_add_admin_field(
			array(
				'parent'        => $second_level_wide_row3,
				'type'          => 'selectblanksimple',
				'name'          => 'dropdown_wide_fontstyle',
				'default_value' => '',
				'label'         => 'Font style',
				'options'       => optimize_mikado_get_font_style_array()
			)
		);

		optimize_mikado_add_admin_field(
			array(
				'parent'        => $second_level_wide_row3,
				'type'          => 'selectblanksimple',
				'name'          => 'dropdown_wide_fontweight',
				'default_value' => '',
				'label'         => 'Font weight',
				'options'       => optimize_mikado_get_font_weight_array()
			)
		);

		optimize_mikado_add_admin_field(
			array(
				'parent'        => $second_level_wide_row3,
				'type'          => 'textsimple',
				'name'          => 'dropdown_wide_letterspacing',
				'default_value' => '',
				'label'         => 'Letter spacing',
				'args'          => array(
					'suffix' => 'px'
				)
			)
		);

		optimize_mikado_add_admin_field(
			array(
				'parent'        => $second_level_wide_row3,
				'type'          => 'selectblanksimple',
				'name'          => 'dropdown_wide_texttransform',
				'default_value' => '',
				'label'         => 'Text Transform',
				'options'       => optimize_mikado_get_text_transform_array()
			)
		);

		$third_level_group = optimize_mikado_add_admin_group(
			array(
				'parent'      => $panel_main_menu,
				'name'        => 'third_level_group',
				'title'       => '3nd Level Menu',
				'description' => 'Define styles for 3nd level in Top Navigation Menu'
			)
		);

		$third_level_row1 = optimize_mikado_add_admin_row(
			array(
				'parent' => $third_level_group,
				'name'   => 'third_level_row1'
			)
		);

		optimize_mikado_add_admin_field(
			array(
				'parent'        => $third_level_row1,
				'type'          => 'colorsimple',
				'name'          => 'dropdown_color_thirdlvl',
				'default_value' => '',
				'label'         => 'Text Color'
			)
		);

		optimize_mikado_add_admin_field(
			array(
				'parent'        => $third_level_row1,
				'type'          => 'colorsimple',
				'name'          => 'dropdown_hovercolor_thirdlvl',
				'default_value' => '',
				'label'         => 'Hover/Active Color'
			)
		);

		optimize_mikado_add_admin_field(
			array(
				'parent'        => $third_level_row1,
				'type'          => 'colorsimple',
				'name'          => 'dropdown_background_hovercolor_thirdlvl',
				'default_value' => '',
				'label'         => 'Hover/Active Background Color'
			)
		);

		$third_level_row2 = optimize_mikado_add_admin_row(
			array(
				'parent' => $third_level_group,
				'name'   => 'third_level_row2',
				'next'   => true
			)
		);

		optimize_mikado_add_admin_field(
			array(
				'parent'        => $third_level_row2,
				'type'          => 'fontsimple',
				'name'          => 'dropdown_google_fonts_thirdlvl',
				'default_value' => '-1',
				'label'         => 'Font Family'
			)
		);

		optimize_mikado_add_admin_field(
			array(
				'parent'        => $third_level_row2,
				'type'          => 'textsimple',
				'name'          => 'dropdown_fontsize_thirdlvl',
				'default_value' => '',
				'label'         => 'Font Size',
				'args'          => array(
					'suffix' => 'px'
				)
			)
		);

		optimize_mikado_add_admin_field(
			array(
				'parent'        => $third_level_row2,
				'type'          => 'textsimple',
				'name'          => 'dropdown_lineheight_thirdlvl',
				'default_value' => '',
				'label'         => 'Line Height',
				'args'          => array(
					'suffix' => 'px'
				)
			)
		);

		$third_level_row3 = optimize_mikado_add_admin_row(
			array(
				'parent' => $third_level_group,
				'name'   => 'third_level_row3',
				'next'   => true
			)
		);

		optimize_mikado_add_admin_field(
			array(
				'parent'        => $third_level_row3,
				'type'          => 'selectblanksimple',
				'name'          => 'dropdown_fontstyle_thirdlvl',
				'default_value' => '',
				'label'         => 'Font style',
				'options'       => optimize_mikado_get_font_style_array()
			)
		);

		optimize_mikado_add_admin_field(
			array(
				'parent'        => $third_level_row3,
				'type'          => 'selectblanksimple',
				'name'          => 'dropdown_fontweight_thirdlvl',
				'default_value' => '',
				'label'         => 'Font weight',
				'options'       => optimize_mikado_get_font_weight_array()
			)
		);

		optimize_mikado_add_admin_field(
			array(
				'parent'        => $third_level_row3,
				'type'          => 'textsimple',
				'name'          => 'dropdown_letterspacing_thirdlvl',
				'default_value' => '',
				'label'         => 'Letter spacing',
				'args'          => array(
					'suffix' => 'px'
				)
			)
		);

		optimize_mikado_add_admin_field(
			array(
				'parent'        => $third_level_row3,
				'type'          => 'selectblanksimple',
				'name'          => 'dropdown_texttransform_thirdlvl',
				'default_value' => '',
				'label'         => 'Text Transform',
				'options'       => optimize_mikado_get_text_transform_array()
			)
		);


		/***********************************************************/
		$third_level_wide_group = optimize_mikado_add_admin_group(
			array(
				'parent'      => $panel_main_menu,
				'name'        => 'third_level_wide_group',
				'title'       => '3rd Level Wide Menu',
				'description' => 'Define styles for 3rd level in Wide Menu'
			)
		);

		$third_level_wide_row1 = optimize_mikado_add_admin_row(
			array(
				'parent' => $third_level_wide_group,
				'name'   => 'third_level_wide_row1'
			)
		);

		optimize_mikado_add_admin_field(
			array(
				'parent'        => $third_level_wide_row1,
				'type'          => 'colorsimple',
				'name'          => 'dropdown_wide_color_thirdlvl',
				'default_value' => '',
				'label'         => 'Text Color'
			)
		);

		optimize_mikado_add_admin_field(
			array(
				'parent'        => $third_level_wide_row1,
				'type'          => 'colorsimple',
				'name'          => 'dropdown_wide_hovercolor_thirdlvl',
				'default_value' => '',
				'label'         => 'Hover/Active Color'
			)
		);

		optimize_mikado_add_admin_field(
			array(
				'parent'        => $third_level_wide_row1,
				'type'          => 'colorsimple',
				'name'          => 'dropdown_wide_background_hovercolor_thirdlvl',
				'default_value' => '',
				'label'         => 'Hover/Active Background Color'
			)
		);

		$third_level_wide_row2 = optimize_mikado_add_admin_row(
			array(
				'parent' => $third_level_wide_group,
				'name'   => 'third_level_wide_row2',
				'next'   => true
			)
		);

		optimize_mikado_add_admin_field(
			array(
				'parent'        => $third_level_wide_row2,
				'type'          => 'fontsimple',
				'name'          => 'dropdown_wide_google_fonts_thirdlvl',
				'default_value' => '-1',
				'label'         => 'Font Family'
			)
		);

		optimize_mikado_add_admin_field(
			array(
				'parent'        => $third_level_wide_row2,
				'type'          => 'textsimple',
				'name'          => 'dropdown_wide_fontsize_thirdlvl',
				'default_value' => '',
				'label'         => 'Font Size',
				'args'          => array(
					'suffix' => 'px'
				)
			)
		);

		optimize_mikado_add_admin_field(
			array(
				'parent'        => $third_level_wide_row2,
				'type'          => 'textsimple',
				'name'          => 'dropdown_wide_lineheight_thirdlvl',
				'default_value' => '',
				'label'         => 'Line Height',
				'args'          => array(
					'suffix' => 'px'
				)
			)
		);

		$third_level_wide_row3 = optimize_mikado_add_admin_row(
			array(
				'parent' => $third_level_wide_group,
				'name'   => 'third_level_wide_row3',
				'next'   => true
			)
		);

		optimize_mikado_add_admin_field(
			array(
				'parent'        => $third_level_wide_row3,
				'type'          => 'selectblanksimple',
				'name'          => 'dropdown_wide_fontstyle_thirdlvl',
				'default_value' => '',
				'label'         => 'Font style',
				'options'       => optimize_mikado_get_font_style_array()
			)
		);

		optimize_mikado_add_admin_field(
			array(
				'parent'        => $third_level_wide_row3,
				'type'          => 'selectblanksimple',
				'name'          => 'dropdown_wide_fontweight_thirdlvl',
				'default_value' => '',
				'label'         => 'Font weight',
				'options'       => optimize_mikado_get_font_weight_array()
			)
		);

		optimize_mikado_add_admin_field(
			array(
				'parent'        => $third_level_wide_row3,
				'type'          => 'textsimple',
				'name'          => 'dropdown_wide_letterspacing_thirdlvl',
				'default_value' => '',
				'label'         => 'Letter spacing',
				'args'          => array(
					'suffix' => 'px'
				)
			)
		);

		optimize_mikado_add_admin_field(
			array(
				'parent'        => $third_level_wide_row3,
				'type'          => 'selectblanksimple',
				'name'          => 'dropdown_wide_texttransform_thirdlvl',
				'default_value' => '',
				'label'         => 'Text Transform',
				'options'       => optimize_mikado_get_text_transform_array()
			)
		);

		$panel_vertical_main_menu = optimize_mikado_add_admin_panel(
			array(
				'title'           => 'Vertical Main Menu',
				'name'            => 'panel_vertical_main_menu',
				'page'            => '_header_page',
				'hidden_property' => 'header_type',
				'hidden_values'   => array(
					'header-standard'
				)
			)
		);

		$drop_down_group = optimize_mikado_add_admin_group(
			array(
				'parent'      => $panel_vertical_main_menu,
				'name'        => 'vertical_drop_down_group',
				'title'       => 'Main Dropdown Menu',
				'description' => 'Set a style for dropdown menu'
			)
		);

		$vertical_drop_down_row1 = optimize_mikado_add_admin_row(
			array(
				'parent' => $drop_down_group,
				'name'   => 'mkdf_drop_down_row1',
			)
		);

		optimize_mikado_add_admin_field(
			array(
				'parent'        => $vertical_drop_down_row1,
				'type'          => 'colorsimple',
				'name'          => 'vertical_dropdown_background_color',
				'default_value' => '',
				'label'         => 'Background Color',
			)
		);

		$group_vertical_first_level = optimize_mikado_add_admin_group(array(
			'name'        => 'group_vertical_first_level',
			'title'       => '1st level',
			'description' => 'Define styles for 1st level menu',
			'parent'      => $panel_vertical_main_menu
		));

		$row_vertical_first_level_1 = optimize_mikado_add_admin_row(array(
			'name'   => 'row_vertical_first_level_1',
			'parent' => $group_vertical_first_level
		));

		optimize_mikado_add_admin_field(array(
			'type'          => 'colorsimple',
			'name'          => 'vertical_menu_1st_color',
			'default_value' => '',
			'label'         => 'Text Color',
			'parent'        => $row_vertical_first_level_1
		));

		optimize_mikado_add_admin_field(array(
			'type'          => 'colorsimple',
			'name'          => 'vertical_menu_1st_hover_color',
			'default_value' => '',
			'label'         => 'Hover/Active Color',
			'parent'        => $row_vertical_first_level_1
		));

		optimize_mikado_add_admin_field(array(
			'type'          => 'textsimple',
			'name'          => 'vertical_menu_1st_fontsize',
			'default_value' => '',
			'label'         => 'Font Size',
			'args'          => array(
				'suffix' => 'px'
			),
			'parent'        => $row_vertical_first_level_1
		));

		optimize_mikado_add_admin_field(array(
			'type'          => 'textsimple',
			'name'          => 'vertical_menu_1st_lineheight',
			'default_value' => '',
			'label'         => 'Line Height',
			'args'          => array(
				'suffix' => 'px'
			),
			'parent'        => $row_vertical_first_level_1
		));

		$row_vertical_first_level_2 = optimize_mikado_add_admin_row(array(
			'name'   => 'row_vertical_first_level_2',
			'parent' => $group_vertical_first_level,
			'next'   => true
		));

		optimize_mikado_add_admin_field(array(
			'type'          => 'selectblanksimple',
			'name'          => 'vertical_menu_1st_texttransform',
			'default_value' => '',
			'label'         => 'Text Transform',
			'options'       => optimize_mikado_get_text_transform_array(),
			'parent'        => $row_vertical_first_level_2
		));

		optimize_mikado_add_admin_field(array(
			'type'          => 'fontsimple',
			'name'          => 'vertical_menu_1st_google_fonts',
			'default_value' => '-1',
			'label'         => 'Font Family',
			'parent'        => $row_vertical_first_level_2
		));

		optimize_mikado_add_admin_field(array(
			'type'          => 'selectblanksimple',
			'name'          => 'vertical_menu_1st_fontstyle',
			'default_value' => '',
			'label'         => 'Font Style',
			'options'       => optimize_mikado_get_font_style_array(),
			'parent'        => $row_vertical_first_level_2
		));

		optimize_mikado_add_admin_field(array(
			'type'          => 'selectblanksimple',
			'name'          => 'vertical_menu_1st_fontweight',
			'default_value' => '',
			'label'         => 'Font Weight',
			'options'       => optimize_mikado_get_font_weight_array(),
			'parent'        => $row_vertical_first_level_2
		));

		$row_vertical_first_level_3 = optimize_mikado_add_admin_row(array(
			'name'   => 'row_vertical_first_level_3',
			'parent' => $group_vertical_first_level,
			'next'   => true
		));

		optimize_mikado_add_admin_field(array(
			'type'          => 'textsimple',
			'name'          => 'vertical_menu_1st_letter_spacing',
			'default_value' => '',
			'label'         => 'Letter Spacing',
			'args'          => array(
				'suffix' => 'px'
			),
			'parent'        => $row_vertical_first_level_3
		));

		$group_vertical_second_level = optimize_mikado_add_admin_group(array(
			'name'        => 'group_vertical_second_level',
			'title'       => '2nd level',
			'description' => 'Define styles for 2nd level menu',
			'parent'      => $panel_vertical_main_menu
		));

		$row_vertical_second_level_1 = optimize_mikado_add_admin_row(array(
			'name'   => 'row_vertical_second_level_1',
			'parent' => $group_vertical_second_level
		));

		optimize_mikado_add_admin_field(array(
			'type'          => 'colorsimple',
			'name'          => 'vertical_menu_2nd_color',
			'default_value' => '',
			'label'         => 'Text Color',
			'parent'        => $row_vertical_second_level_1
		));

		optimize_mikado_add_admin_field(array(
			'type'          => 'colorsimple',
			'name'          => 'vertical_menu_2nd_hover_color',
			'default_value' => '',
			'label'         => 'Hover/Active Color',
			'parent'        => $row_vertical_second_level_1
		));

		optimize_mikado_add_admin_field(array(
			'type'          => 'textsimple',
			'name'          => 'vertical_menu_2nd_fontsize',
			'default_value' => '',
			'label'         => 'Font Size',
			'args'          => array(
				'suffix' => 'px'
			),
			'parent'        => $row_vertical_second_level_1
		));

		optimize_mikado_add_admin_field(array(
			'type'          => 'textsimple',
			'name'          => 'vertical_menu_2nd_lineheight',
			'default_value' => '',
			'label'         => 'Line Height',
			'args'          => array(
				'suffix' => 'px'
			),
			'parent'        => $row_vertical_second_level_1
		));

		$row_vertical_second_level_2 = optimize_mikado_add_admin_row(array(
			'name'   => 'row_vertical_second_level_2',
			'parent' => $group_vertical_second_level,
			'next'   => true
		));

		optimize_mikado_add_admin_field(array(
			'type'          => 'selectblanksimple',
			'name'          => 'vertical_menu_2nd_texttransform',
			'default_value' => '',
			'label'         => 'Text Transform',
			'options'       => optimize_mikado_get_text_transform_array(),
			'parent'        => $row_vertical_second_level_2
		));

		optimize_mikado_add_admin_field(array(
			'type'          => 'fontsimple',
			'name'          => 'vertical_menu_2nd_google_fonts',
			'default_value' => '-1',
			'label'         => 'Font Family',
			'parent'        => $row_vertical_second_level_2
		));

		optimize_mikado_add_admin_field(array(
			'type'          => 'selectblanksimple',
			'name'          => 'vertical_menu_2nd_fontstyle',
			'default_value' => '',
			'label'         => 'Font Style',
			'options'       => optimize_mikado_get_font_style_array(),
			'parent'        => $row_vertical_second_level_2
		));

		optimize_mikado_add_admin_field(array(
			'type'          => 'selectblanksimple',
			'name'          => 'vertical_menu_2nd_fontweight',
			'default_value' => '',
			'label'         => 'Font Weight',
			'options'       => optimize_mikado_get_font_weight_array(),
			'parent'        => $row_vertical_second_level_2
		));

		$row_vertical_second_level_3 = optimize_mikado_add_admin_row(array(
			'name'   => 'row_vertical_second_level_3',
			'parent' => $group_vertical_second_level,
			'next'   => true
		));

		optimize_mikado_add_admin_field(array(
			'type'          => 'textsimple',
			'name'          => 'vertical_menu_2nd_letter_spacing',
			'default_value' => '',
			'label'         => 'Letter Spacing',
			'args'          => array(
				'suffix' => 'px'
			),
			'parent'        => $row_vertical_second_level_3
		));

		$group_vertical_third_level = optimize_mikado_add_admin_group(array(
			'name'        => 'group_vertical_third_level',
			'title'       => '3rd level',
			'description' => 'Define styles for 3rd level menu',
			'parent'      => $panel_vertical_main_menu
		));

		$row_vertical_third_level_1 = optimize_mikado_add_admin_row(array(
			'name'   => 'row_vertical_third_level_1',
			'parent' => $group_vertical_third_level
		));

		optimize_mikado_add_admin_field(array(
			'type'          => 'colorsimple',
			'name'          => 'vertical_menu_3rd_color',
			'default_value' => '',
			'label'         => 'Text Color',
			'parent'        => $row_vertical_third_level_1
		));

		optimize_mikado_add_admin_field(array(
			'type'          => 'colorsimple',
			'name'          => 'vertical_menu_3rd_hover_color',
			'default_value' => '',
			'label'         => 'Hover/Active Color',
			'parent'        => $row_vertical_third_level_1
		));

		optimize_mikado_add_admin_field(array(
			'type'          => 'textsimple',
			'name'          => 'vertical_menu_3rd_fontsize',
			'default_value' => '',
			'label'         => 'Font Size',
			'args'          => array(
				'suffix' => 'px'
			),
			'parent'        => $row_vertical_third_level_1
		));

		optimize_mikado_add_admin_field(array(
			'type'          => 'textsimple',
			'name'          => 'vertical_menu_3rd_lineheight',
			'default_value' => '',
			'label'         => 'Line Height',
			'args'          => array(
				'suffix' => 'px'
			),
			'parent'        => $row_vertical_third_level_1
		));

		$row_vertical_third_level_2 = optimize_mikado_add_admin_row(array(
			'name'   => 'row_vertical_third_level_2',
			'parent' => $group_vertical_third_level,
			'next'   => true
		));

		optimize_mikado_add_admin_field(array(
			'type'          => 'selectblanksimple',
			'name'          => 'vertical_menu_3rd_texttransform',
			'default_value' => '',
			'label'         => 'Text Transform',
			'options'       => optimize_mikado_get_text_transform_array(),
			'parent'        => $row_vertical_third_level_2
		));

		optimize_mikado_add_admin_field(array(
			'type'          => 'fontsimple',
			'name'          => 'vertical_menu_3rd_google_fonts',
			'default_value' => '-1',
			'label'         => 'Font Family',
			'parent'        => $row_vertical_third_level_2
		));

		optimize_mikado_add_admin_field(array(
			'type'          => 'selectblanksimple',
			'name'          => 'vertical_menu_3rd_fontstyle',
			'default_value' => '',
			'label'         => 'Font Style',
			'options'       => optimize_mikado_get_font_style_array(),
			'parent'        => $row_vertical_third_level_2
		));

		optimize_mikado_add_admin_field(array(
			'type'          => 'selectblanksimple',
			'name'          => 'vertical_menu_3rd_fontweight',
			'default_value' => '',
			'label'         => 'Font Weight',
			'options'       => optimize_mikado_get_font_weight_array(),
			'parent'        => $row_vertical_third_level_2
		));

		$row_vertical_third_level_3 = optimize_mikado_add_admin_row(array(
			'name'   => 'row_vertical_third_level_3',
			'parent' => $group_vertical_third_level,
			'next'   => true
		));

		optimize_mikado_add_admin_field(array(
			'type'          => 'textsimple',
			'name'          => 'vertical_menu_3rd_letter_spacing',
			'default_value' => '',
			'label'         => 'Letter Spacing',
			'args'          => array(
				'suffix' => 'px'
			),
			'parent'        => $row_vertical_third_level_3
		));

		$panel_mobile_header = optimize_mikado_add_admin_panel(array(
			'title' => 'Mobile header',
			'name'  => 'panel_mobile_header',
			'page'  => '_header_page'
		));

		optimize_mikado_add_admin_field(array(
			'name'        => 'mobile_header_height',
			'type'        => 'text',
			'label'       => 'Mobile Header Height',
			'description' => 'Enter height for mobile header in pixels',
			'parent'      => $panel_mobile_header,
			'args'        => array(
				'col_width' => 3,
				'suffix'    => 'px'
			)
		));

		optimize_mikado_add_admin_field(array(
			'name'        => 'mobile_header_background_color',
			'type'        => 'color',
			'label'       => 'Mobile Header Background Color',
			'description' => 'Choose color for mobile header',
			'parent'      => $panel_mobile_header
		));

		optimize_mikado_add_admin_field(array(
			'name'        => 'mobile_menu_background_color',
			'type'        => 'color',
			'label'       => 'Mobile Menu Background Color',
			'description' => 'Choose color for mobile menu',
			'parent'      => $panel_mobile_header
		));

		optimize_mikado_add_admin_field(array(
			'name'        => 'mobile_menu_separator_color',
			'type'        => 'color',
			'label'       => 'Mobile Menu Item Separator Color',
			'description' => 'Choose color for mobile menu horizontal separators',
			'parent'      => $panel_mobile_header
		));

		optimize_mikado_add_admin_field(array(
			'name'        => 'mobile_logo_height',
			'type'        => 'text',
			'label'       => 'Logo Height For Mobile Header',
			'description' => 'Define logo height for screen size smaller than 1000px',
			'parent'      => $panel_mobile_header,
			'args'        => array(
				'col_width' => 3,
				'suffix'    => 'px'
			)
		));

		optimize_mikado_add_admin_field(array(
			'name'        => 'mobile_logo_height_phones',
			'type'        => 'text',
			'label'       => 'Logo Height For Mobile Devices',
			'description' => 'Define logo height for screen size smaller than 480px',
			'parent'      => $panel_mobile_header,
			'args'        => array(
				'col_width' => 3,
				'suffix'    => 'px'
			)
		));

		optimize_mikado_add_admin_section_title(array(
			'parent' => $panel_mobile_header,
			'name'   => 'mobile_header_fonts_title',
			'title'  => 'Typography'
		));

		optimize_mikado_add_admin_field(array(
			'name'        => 'mobile_text_color',
			'type'        => 'color',
			'label'       => 'Navigation Text Color',
			'description' => 'Define color for mobile navigation text',
			'parent'      => $panel_mobile_header
		));

		optimize_mikado_add_admin_field(array(
			'name'        => 'mobile_text_hover_color',
			'type'        => 'color',
			'label'       => 'Navigation Hover/Active Color',
			'description' => 'Define hover/active color for mobile navigation text',
			'parent'      => $panel_mobile_header
		));

		optimize_mikado_add_admin_field(array(
			'name'        => 'mobile_font_family',
			'type'        => 'font',
			'label'       => 'Navigation Font Family',
			'description' => 'Define font family for mobile navigation text',
			'parent'      => $panel_mobile_header
		));

		optimize_mikado_add_admin_field(array(
			'name'        => 'mobile_font_size',
			'type'        => 'text',
			'label'       => 'Navigation Font Size',
			'description' => 'Define font size for mobile navigation text',
			'parent'      => $panel_mobile_header,
			'args'        => array(
				'col_width' => 3,
				'suffix'    => 'px'
			)
		));

		optimize_mikado_add_admin_field(array(
			'name'        => 'mobile_line_height',
			'type'        => 'text',
			'label'       => 'Navigation Line Height',
			'description' => 'Define line height for mobile navigation text',
			'parent'      => $panel_mobile_header,
			'args'        => array(
				'col_width' => 3,
				'suffix'    => 'px'
			)
		));

		optimize_mikado_add_admin_field(array(
			'name'        => 'mobile_text_transform',
			'type'        => 'select',
			'label'       => 'Navigation Text Transform',
			'description' => 'Define text transform for mobile navigation text',
			'parent'      => $panel_mobile_header,
			'options'     => optimize_mikado_get_text_transform_array(true)
		));

		optimize_mikado_add_admin_field(array(
			'name'        => 'mobile_font_style',
			'type'        => 'select',
			'label'       => 'Navigation Font Style',
			'description' => 'Define font style for mobile navigation text',
			'parent'      => $panel_mobile_header,
			'options'     => optimize_mikado_get_font_style_array(true)
		));

		optimize_mikado_add_admin_field(array(
			'name'        => 'mobile_font_weight',
			'type'        => 'select',
			'label'       => 'Navigation Font Weight',
			'description' => 'Define font weight for mobile navigation text',
			'parent'      => $panel_mobile_header,
			'options'     => optimize_mikado_get_font_weight_array(true)
		));

		optimize_mikado_add_admin_section_title(array(
			'name' => 'mobile_opener_panel',
			'parent' => $panel_mobile_header,
			'title' => 'Mobile Menu Opener'
		));

		optimize_mikado_add_admin_field(array(
			'name'        => 'mobile_icon_pack',
			'type'        => 'select',
			'label'       => 'Mobile Navigation Icon Pack',
			'default_value' => 'font_awesome',
			'description' => 'Choose icon pack for mobile navigation icon',
			'parent'      => $panel_mobile_header,
			'options'     => optimize_mikado_icon_collections()->getIconCollectionsExclude(array('linea_icons', 'simple_line_icons'))
		));

		optimize_mikado_add_admin_field(array(
			'name'        => 'mobile_icon_color',
			'type'        => 'color',
			'label'       => 'Mobile Navigation Icon Color',
			'description' => 'Choose color for icon header',
			'parent'      => $panel_mobile_header
		));

		optimize_mikado_add_admin_field(array(
			'name'        => 'mobile_icon_hover_color',
			'type'        => 'color',
			'label'       => 'Mobile Navigation Icon Hover Color',
			'description' => 'Choose hover color for mobile navigation icon ',
			'parent'      => $panel_mobile_header
		));

		optimize_mikado_add_admin_field(array(
			'name'        => 'mobile_icon_size',
			'type'        => 'text',
			'label'       => 'Mobile Navigation Icon size',
			'description' => 'Choose size for mobile navigation icon ',
			'parent'      => $panel_mobile_header,
			'args' => array(
				'col_width' => 3,
				'suffix' => 'px'
			)
		));
	}

	add_action('optimize_mikado_options_map', 'optimize_mikado_header_options_map', 3);

}