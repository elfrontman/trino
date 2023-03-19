<?php // This line is needed for mixItUp gutter ?>
<article <?php post_class('mkdf-portfolio-item mix  '.$categories); ?>>
	<a itemprop="url" class ="mkdf-portfolio-link" href="<?php echo esc_url($item_link); ?>"></a>
	<div itemprop="image" class = "mkdf-ptf-item-image-holder">
		<?php if($use_custom_image_size && (is_array($custom_image_sizes) && count($custom_image_sizes))) : ?>
			<?php echo optimize_mikado_generate_thumbnail(get_post_thumbnail_id(get_the_ID()), null, $custom_image_sizes[0], $custom_image_sizes[1]); ?>
		<?php else: ?>
			<?php the_post_thumbnail($thumb_size); ?>
		<?php endif; ?>
	</div>
	<div class="mkdf-ptf-item-overlay" <?php mkd_core_inline_style($overlay_styles); ?>>
		<div class="mkdf-ptf-item-text-overlay-inner">
			<div class="mkdf-ptf-item-text-holder">
				<<?php echo esc_attr($title_tag)?> itemprop="headline" class="mkdf-ptf-item-title">
					<a itemprop="url" href="<?php echo esc_url($item_link)?>">
						<?php the_title(); ?>
					</a>
				</<?php echo esc_attr($title_tag)?>>

				<?php if(!empty($category_html) || function_exists('optimize_mikado_like_portfolio_list')) : ?>
					<div class="mkdf-ptf-item-bottom">
						<?php if(!empty($category_html)) : ?>
							<?php print $category_html; ?>
						<?php endif; ?>

						<?php if(function_exists('optimize_mikado_like_portfolio_list')) : ?>
							<?php echo optimize_mikado_like_portfolio_list(get_the_ID()); ?>
						<?php endif; ?>
					</div>
				<?php endif; ?>
			</div>
		</div>	
	</div>
</article>
<?php // This line is needed for mixItUp gutter ?>