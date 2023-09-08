﻿#include "PlayerBullet.h"
#include <cassert>

void PlayerBullet::Initialize(uint32_t texture, const Vector2& pos, Vector2 velosity) {
	assert(texture != 0u);
	// 初期化
	texture_ = texture;
	pos_ = pos;
	velocity_ = velosity;
	bulletSpeed_ = 20.0f;
		
	// スプライトの生成
	sprite_.reset(Sprite::Create(texture, pos_, {1.0f, 1.0f, 1.0f, 1.0f}, {0.5f, 0.5f}));
	// サイズ設定
	sprite_->SetSize({16.0f, 16.0f});
	radius_ = sprite_->GetSize().x / 2;
}

void PlayerBullet::Update() { 
	
	pos_.x += velocity_.x * bulletSpeed_;
	pos_.y += velocity_.y * bulletSpeed_;

	BaseBullet::Update();
}

void PlayerBullet::Draw() { 
	
	//
	sprite_->Draw();
}

void PlayerBullet::OnCollision() 
{ 
	isDead_ = true;
}
