<?php

if(!function_exists('optimize_mikado_register_widgets')) {

	function optimize_mikado_register_widgets() {

		$widgets = array(
			'OptimizeMikadoLatestPosts',
			'OptimizeMikadoSearchOpener',
			'OptimizeMikadoSideAreaOpener',
			'OptimizeMikadoStickySidebar',
			'OptimizeMikadoSocialIconWidget',
			'OptimizeMikadoSeparatorWidget',
			'OptimizeMikadoCallToActionButton'
		);

		foreach($widgets as $widget) {
			register_widget($widget);
		}
	}
}

add_action('widgets_init', 'optimize_mikado_register_widgets');