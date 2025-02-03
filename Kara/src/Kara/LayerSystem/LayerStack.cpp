#include "pch.hpp"

#include "LayerStack.hpp"

#include "Kara/LayerSystem/Layer.hpp"

namespace Kara {
namespace LayerSystem {
LayerStack::~LayerStack() {
  for (auto layer : mLayers) {
    delete layer;
  }
}

void LayerStack::Push(Layer *aLayer) { mLayers.emplace_back(aLayer); }

void LayerStack::Pop(Layer *aLayer) {
  const auto it = std::find(mLayers.begin(), mLayers.end(), aLayer);
  if (it != mLayers.end()) {
    mLayers.erase(it);
  }
}

} // namespace LayerSystem
} // namespace Kara