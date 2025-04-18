#include "pch.hpp"

#include "LayerStack.hpp"

#include "Kara/Layers/Layer.hpp"

namespace Kara {
namespace Layers {
LayerStack::~LayerStack() {
  for (auto layer : mLayers) {
    delete layer;
  }

  for (auto layer : mLayers) {
    delete layer;
  }
}

void LayerStack::Push(Layer *aLayer) {
  mLayers.emplace_back(aLayer);
  aLayer->OnAttach();
}

void LayerStack::Pop(Layer *aLayer) {
  const auto it = std::find(mLayers.begin(), mLayers.end(), aLayer);
  if (it != mLayers.end()) {
    mLayers.erase(it);
  }
  aLayer->OnDetach();
}

void LayerStack::PushOverlay(Layer *aLayer) {
  mOverlays.emplace_back(aLayer);
  aLayer->OnAttach();
}

void LayerStack::PopOverlay(Layer *aLayer) {
  const auto it = std::find(mOverlays.begin(), mOverlays.end(), aLayer);
  if (it != mOverlays.end()) {
    mOverlays.erase(it);
  }

  aLayer->OnDetach();
}

void LayerStack::map(const std::function<void(Layer *)> &aFunc) {
  for (auto layer : mLayers) {
    aFunc(layer);
  }

  for (auto layer : mOverlays) {
    aFunc(layer);
  }
}

void LayerStack::mapi(const std::function<bool(Layer *)> &aFunc) {
  auto skip{false};
  for (auto it = mOverlays.end(); it != mOverlays.begin() && !skip;) {
    if (aFunc(*--it)) {
      skip = true;
    }
  }

  for (auto it = mLayers.end(); it != mLayers.begin() && !skip;) {
    if (aFunc(*--it)) {
      skip = true;
    }
  }
}

} // namespace Layers
} // namespace Kara